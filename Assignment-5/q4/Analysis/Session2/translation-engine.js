$(document).ready(function () {
    var url = window.location.search;
    var lang = url.substring(url.indexOf("?lang=")+ 6 , url.length);
    translateTo(lang)
});

function translateTo(lang){
    //'en-US', 'fr-FR', 'de-de', 'ru', 'zh-CN', 'ja', 'ko'
    switch(lang) {
        case 'fr-FR':
            parseAndTranslate(LANG_FR_TRANS);
            break;
        case 'de-de':
            parseAndTranslate(LANG_DE_TRANS);
            break;
        case 'ru':
            parseAndTranslate(LANG_RU_TRANS);
            break;
        case 'zh-CN':
            parseAndTranslate(LANG_CN_TRANS);
            break;
        case 'ja':
            parseAndTranslate(LANG_JA_TRANS);
            break;
        case 'ko':
            parseAndTranslate(LANG_KO_TRANS);
            break;
        default:
            return;
    }
}

function parseAndTranslate(LANG_DICT){
    $('div').each(function(i) {
        var elementHtml = $(this).html().replace(/&nbsp;/gi,'').trim();
        if (elementHtml != ""){
            if (elementHtml in LANG_DICT){
                $(this).html(LANG_DICT[elementHtml]);
            }
        }
    });
    $('a').each(function(i) {
        var elementHtml = $(this).html().replace(/&nbsp;/gi,'').trim();
        if (elementHtml != ""){
            if (elementHtml in LANG_DICT){
                $(this).html(LANG_DICT[elementHtml]);
            }
        }
    });
    $('span').each(function(i) {
        var elementHtml = $(this).html().replace(/&nbsp;/gi,'').trim();
        if (elementHtml != ""){
            if (elementHtml in LANG_DICT){
                $(this).html(LANG_DICT[elementHtml]);
            }
        }
    });
    $('tspan').each(function(i) {
        var elementHtml = $(this).html().replace(/&nbsp;/gi,'').trim();
        if (elementHtml != ""){
            if (elementHtml in LANG_DICT){
                $(this).html(LANG_DICT[elementHtml]);
            }
        }
    });
    $('th').each(function(i) {
        var elementHtml = $(this).html().replace(/&nbsp;/gi,'').trim();
        if (elementHtml != ""){
            if (elementHtml in LANG_DICT){
                $(this).html(LANG_DICT[elementHtml]);
            }
        }
    });
    $('td').each(function(i) {
        var elementHtml = $(this).html().replace(/&nbsp;/gi,'').trim();
        if (elementHtml != ""){
            if (elementHtml in LANG_DICT){
                $(this).html(LANG_DICT[elementHtml]);
            }
        }
    });
    $('font').each(function(i) {
        var elementHtml = $(this).html().replace(/&nbsp;/gi,'').trim();
        if (elementHtml != ""){
            if (elementHtml in LANG_DICT){
                $(this).html(LANG_DICT[elementHtml]);
            }
            if (elementHtml.includes("Seconds")){
                $(this).html(elementHtml.replace("Seconds",LANG_DICT["Seconds"]));
            }
            if (elementHtml.includes("Second")){
                $(this).html(elementHtml.replace("Seconds",LANG_DICT["Second"]));
            }
        }
    });
    $('option').each(function(i) {
        var elementHtml = $(this).html().replace(/&nbsp;/gi,'').trim();
        if (elementHtml != ""){
            if (elementHtml in LANG_DICT){
                $(this).html(LANG_DICT[elementHtml]);
            }
        }
    });
    $('label').each(function(i) {
        var elementHtml = $(this).html().replace(/&nbsp;/gi,'').trim();
        if (elementHtml != ""){
            if (elementHtml.includes("Show:")){
                $(this).html(elementHtml.replace("Show:",LANG_DICT["Show:"]));
            }
            if (elementHtml.includes("SLA Status:")){
                $(this).html(elementHtml.replace("SLA Status:",LANG_DICT["SLA Status:"]));
            }
        }
    });
}