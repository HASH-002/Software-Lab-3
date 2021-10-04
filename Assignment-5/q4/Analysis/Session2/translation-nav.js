$(document).ready(function () {
    var url = window.location.search;
    
    $('#toc_content').attr("src", $('#toc_content').attr("src") + url);
    $('#page_content').attr("src", $('#page_content').attr("src") + url);

    $('a').each(function(i) {
        var oldHref = $(this).attr("href");
        $(this).attr("href", oldHref + url);
    });
});