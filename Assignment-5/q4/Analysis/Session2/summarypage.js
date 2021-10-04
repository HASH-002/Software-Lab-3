var myChart;
var RESOURCES_DICT;

$(document).ready(function () {
	var url = window.location.search;
    var lang = url.substring(url.indexOf("?lang=")+ 6 , url.length);
	switchToTranslation(lang);
	$.fn.dataTable.ext.search.push(
		function( settings, data, dataIndex ) {
			if ( settings.nTable.id !== 'TransactionsTable' ) {
				return true;
			}
			var selected = $('#sla-status-filter option:selected').index();
			if(selected <= 0)
				return true;
			if(selected == data[1])
				return true;
			return false;
		}
	);

	if(document.title != "" && $("#mainContainer").attr("title") != "cross-result")
		InitSummaryPage();
		
	$('#mainContainer').removeClass('hidden');
	$('#loading').addClass('hidden');
});

function switchToTranslation(lang){
    //'en-US', 'fr-FR', 'de-de', 'ru', 'zh-CN', 'ja', 'ko'
    switch(lang) {
        case 'fr-FR':
            RESOURCES_DICT = LANG_FR_TRANS;
            break;
        case 'de-de':
            RESOURCES_DICT = LANG_DE_TRANS;
            break;
        case 'ru':
            RESOURCES_DICT = LANG_RU_TRANS;
            break;
        case 'zh-CN':
            RESOURCES_DICT = LANG_CN_TRANS;
            break;
        case 'ja':
            RESOURCES_DICT = LANG_JA_TRANS;
            break;
        case 'ko':
            RESOURCES_DICT = LANG_KO_TRANS;
            break;
        default:
            RESOURCES_DICT = LR_RESOURCES;
    }
}

function format ( tableRowData ) {
	var start, end;
	if (tableRowData[0].indexOf('0000(') != -1){
		start = tableRowData[0].indexOf('0000(') + 5;
		end = tableRowData[0].indexOf(')0000');
	}
	else{
		start = tableRowData[0].indexOf('<div>') + 5;
		end = tableRowData[0].indexOf('</div>');
	}
	var className = "NVB_" + tableRowData[0].substring(start,end);
	var count = document.getElementsByClassName(className).length;
	if(count == 0)
		return "";
	var result = "";

	var i;
	for (i = 0; i < count; i++){
		var cells = document.getElementsByClassName(className)[i].cells;
		var j;
		result = result + '<tr class="NV-child-row">';
		for(j = 0; j < cells.length; j++){			
			result = result + '<td>';
			result = result + cells[j].innerHTML;
			result = result + '</td>';
		}
		result = result + '</tr>';
	}
    return result;
}

function navigateTo(url){
	if (!OnClickEvents){
		return;
	  }
	OnClickEvents.navigateTo(url);
}

function InitSummaryPage(){
	if (typeof $('#SLATable').html() != 'undefined'){
		$('#SLA-title').removeClass('hidden');
		$('#SLA-description').removeClass('hidden');
	}

	try{
		initSchedulerGraph();
		initTransactionsTable();
		initTransactionsSummaryTable();
		initHttpCodesTable();
		initSLA();
		initTooltips();
	} 
	catch (err){
		console.log("Error occured on generating summary page:" + err)
	}
}

function displayNVData(table){
	if(table.rows().length == 0)
		return;
	table.rows().eq(0).each( function ( index ) {
		var row = table.row( index );
		row.child( $(format(row.data())) ).show();
	} );
}

function addSummaryHeaders(count){
	var strings = [RESOURCES_DICT["PASSED"], RESOURCES_DICT["FAILED"], RESOURCES_DICT["STOPPED"], ""];
	var j = 0;
	$("#TransactionSummaryTable tr").eq(0).find('th').each(function(){
		$(this).after('<th></th>');
	});
	$("#TransactionSummaryTable tr").eq(1).find('td').each(function(){
		$(this).after('<td class="summary-headers">'+ strings[j] +'</td>');
		j += 1;
	});
	for(var i = 2; i < count; i++){
		$("#TransactionSummaryTable tr").eq(i).find('td').each(function(){
			$(this).after('<td></td>');
		});
	}
}

function getSeriesData(){
	myChart.showLoading();
	var sLen = parseInt($("#GroupCount").text());
	for (i = 0; i < sLen; i++) {
		var table = document.getElementById("Values_"+i); 
		var data = [];

		for (var j = 0; j < table.rows.length; j++) {
			var cells = table.rows[j].cells;
			data.push([parseFloat(cells[0].innerHTML)*1000,parseFloat(cells[1].innerHTML)]);
		}
		
		myChart.addSeries({
			name: $("#Values_"+i).attr('title'),
			data: data,
			step: true
			},false);
	}
	myChart.redraw();
	myChart.hideLoading();
}

function initSchedulerGraph(){
	if(document.getElementById("SchedulerGraph"))
	{
		myChart = new Highcharts.Chart('SchedulerGraph', {
			chart: {
				height: 300,
				type: 'line'
			},
			title: {
				text: RESOURCES_DICT["SCHEDULER_TITLE"],
				align: "left"
			},
			credits: { 
				enabled: false 
			},
			plotOptions:{
				series:{
					connectNulls: true
				}
			},
			legend:{
				enabled: false
			},
			xAxis: {
				type:'datetime',
				labels:{
					formatter: function() {
						return Highcharts.dateFormat("%H:%M:%S", this.value);
					}
				}
			},
			yAxis: {	
				title: {	
					text:"Vusers"	
				}	
			},
			tooltip: {
				dateTimeLabelFormats: {
					second: '%H:%M:%S'
				}
			}
			
		});
		getSeriesData();
	}
}

function initTransactionsTable(){
	if(document.getElementById("TransactionsTable")){
		var transTable = $('#TransactionsTable').DataTable({
			"lengthMenu": [[25, 50, 100, -1], ["25 "+RESOURCES_DICT["ENTRIES"], "50 "+RESOURCES_DICT["ENTRIES"], "100 "+RESOURCES_DICT["ENTRIES"], RESOURCES_DICT["ENTRIES_ALL"]]],
			"oLanguage": {
				"sInfo": RESOURCES_DICT["SHOWING_ENTRIES"],
				"sInfoEmpty": RESOURCES_DICT["INFO_EMPTY"],
				"sInfoFiltered": RESOURCES_DICT["INFO_FILTERED"],
				"oPaginate":{
					"sPrevious": "<img class=\"custom-paginate\" src=\"left.svg\">",
					"sNext": "<img class=\"custom-paginate\" src=\"right.svg\">"
					},
				"sLengthMenu": RESOURCES_DICT["SHOW"]+": _MENU_",
				"sZeroRecords": RESOURCES_DICT["ZERO_RECORDS"],
				},
			"dom":
			"<'white-bg'<'d-flex'<'#StatusFilter.item flex-grow'><'#LengthFilter.item flex-grow'l><'item flex-grow'f><'#Legend.item flex-grow'>>>" +
			"<'row'<'col-sm-12'tr>>" +
			"<'row'<'col-sm-12 col-md-5'i><'col-sm-12 col-md-7'p>>"
			
		});	

		
		$('#StatusFilter').html(
			"<div id='sla-status-filter' class='slaStatus_filter dataTables_length'>"+
			"<label>"+RESOURCES_DICT["SLA_STATUS"]+": "+
			"<select class='custom-select custom-select-sm form-control form-control-sm'>"+
			"<option value='0'>"+RESOURCES_DICT["SLA_ALL"]+"      </option>"+
			"<option value='1'>"+RESOURCES_DICT["SLA_PASSED"]+"   </option>"+
			"<option value='2'>"+RESOURCES_DICT["SLA_FAILED"]+"   </option>"+
			"<option value='3'>"+RESOURCES_DICT["SLA_NO_DATA"]+"  </option>"+
			"</select>"+
			"</label>"+
			"</div>"
		);

		$('#sla-status-filter').change( function() {
			transTable.draw();
		});
			
		$('#Legend').html(
			"<label>"+
			RESOURCES_DICT["LEGEND"]+":"+
			"<div>"+RESOURCES_DICT["SLA_PASSED"]+"</div>"+"<img src=\"Status_Success.svg\">"+
			"<div>"+RESOURCES_DICT["SLA_FAILED"]+"</div>"+"<img src=\"Status_Failed.svg\">"+
			"<div>"+RESOURCES_DICT["SLA_NO_DATA"]+"</div>"+"<img src=\"Status_NoData.svg\">"+
			"</label>"
		);
		displayNVData(transTable);
	}
	if(document.getElementById("TransactionsTableCross")){
		var transTable = $('#TransactionsTableCross').DataTable({
			"lengthMenu": [[25, 50, 100, -1], ["25 "+RESOURCES_DICT["ENTRIES"], "50 "+RESOURCES_DICT["ENTRIES"], "100 "+RESOURCES_DICT["ENTRIES"], RESOURCES_DICT["ENTRIES_ALL"]]],
			"oLanguage": {
				"sInfo": RESOURCES_DICT["SHOWING_ENTRIES"],
				"oPaginate":{
					"sPrevious": "<img class=\"custom-paginate\" src=\"left.svg\">",
					"sNext": "<img class=\"custom-paginate\" src=\"right.svg\">"
					},
				"sLengthMenu": RESOURCES_DICT["SHOW"]+": _MENU_"
				},
			"ordering": false,
			"paging": false,
			"bInfo": false,
			"dom":
			"<'white-bg'<'row top-row'<'col-md-12'f>>>" +
			"<'row'<'col-sm-12'tr>>" +
			"<'row'<'col-sm-12 col-md-5'i><'col-sm-12 col-md-7'p>>"
			
		});
	}
}

function initTransactionsSummaryTable(){
	if($("#TransactionSummaryTable tr").length > 0){
		addSummaryHeaders($("#TransactionSummaryTable tr").length);
		var transSummaryTable = $("#TransactionSummaryTable").DataTable({
			"searching": false,
			"ordering": false,
			"paging": false,
			"bInfo": false
		});
		displayNVData(transSummaryTable);
	}
}

function initHttpCodesTable(){
	if(document.getElementById("HTTPCodesTable")){
		var httpTable = $('#HTTPCodesTable').DataTable({
			"ordering": false,
			"paging": false,
			"bInfo": false,
			"dom":
			"<'white-bg margin-top-20'<'row top-row'<'#HTTPTitle.col-md-12'><'col-md-12'f>>>" +
			"<'row'<'col-sm-12'tr>>"
		});;

		$('#HTTPTitle').html(
			"<div class='header1'>"+
			"<label>"+RESOURCES_DICT["HTTP_RESPONSES"]+
			"</label>"+
			"</div>"
		);
		displayNVData(httpTable);
	}
}

function initSLA(){
	if(document.getElementById("SLAStatus")){
		if(document.getElementById("SLAStatus").innerHTML == RESOURCES_DICT["SLA_NOT_DEFINED"]){
			document.getElementById("SLAIcon").src="Icons_SLA.svg";
			$('#SLAIcon').removeClass('top-icon-sla');
			$('#SLAIcon').addClass('top-icon-no-sla');
			$('.sla-status').addClass('hidden');
			$('#Status').addClass('hidden');
			$('#Legend').addClass('hidden');
			$('#StatusFilter').addClass('hidden');
		}
	}
}

function initTooltips(){
	$('#sp-tooltip').prop('title', $('#sp-tooltip').text());
	$('#rt-tooltip').attr('title', $('#rt-tooltip').text());
}