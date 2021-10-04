Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_url("94.0.992.38", 
		"URL=https://config.edge.skype.com/config/v1/Edge/94.0.992.38?clientId=-4395319592885350170&osname=win&client=edge&channel=stable&scpfull=0&scpguard=1&scpfre=0&scpver=2&osver=10.0.19043&osarch=x86_64&osedition=home&wu=0&devicefamily=desktop&uma=1&mngd=0&installdate=1628498728", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_add_cookie("MC1=GUID=cb7c331440284bb584a923b47587c950&HASH=cb7c&LV=202108&V=4&LU=1628766041725; DOMAIN=edge.microsoft.com");

	web_add_header("Sec-Mesh-Client-Arch", 
		"x86_64");

	web_add_header("Sec-Mesh-Client-Edge-Channel", 
		"stable");

	web_add_header("Sec-Mesh-Client-Edge-Version", 
		"94.0.992.38");

	web_add_header("Sec-Mesh-Client-OS", 
		"Windows");

	web_add_header("Sec-Mesh-Client-OS-Version", 
		"10.0.19043");

	web_add_header("Sec-Mesh-Client-WebView", 
		"0");

	web_custom_request("msa", 
		"URL=https://edge.microsoft.com/identity/api/v2/msa", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"disable_features\":\"FtpProtocol\\u003CDisableFTP,NotifySyncOnLanguageDetermined\\u003CHistoryAndOpenTabsSync,msEdgeShoppingPriceHistory\\u003CSendLocaleOnPriceComparison,msEdgeShoppingUI\\u003CEdgeShoppingRollout,msEdgeUseReducedCommitBatchSize\\u003CHistoryAndOpenTabsSync,msPdfEnableLinearization\\u003CmsPdfLinearization,msPriceComparison\\u003CSendLocaleOnPriceComparison,msUpstreamLookAlikeChecks\\u003CDisableTargetEmbeddingAndIDN\",\"enable_features\":\""
		"DnsOverHttps\\u003CDnsOverHttpsUi,DnsOverHttpsUpgrade\\u003CDnsOverHttpsUi,ECSCheck\\u003CECSCheck,LegacyTLSEnforced\\u003CLegacyTLSEnforcedConfig,LegacyTLSWarnings\\u003CLegacyTLSWarningsConfig,OmniboxDemoteByType\\u003CRolloutStableDemoteURL,OmniboxGroupSuggestionsBySearchVsUrl\\u003CPowerExpGroupSuggestionsBySearchVsUrl,OmniboxUIExperimentMaxAutocompleteMatches\\u003CRolloutOmniboxMaxSuggestions,TabHoverCards\\u003CTabPreview,msAADCComplianceUI\\u003CAADCComplianceUI,"
		"msAdaptiveNotificationPermissionUiSelector\\u003CNotificationPermissionAdaptiveUiSelection,msAskBeforeClosingMultipleTabs\\u003CSpeedBump,msCollectExperimentationGuardrailMetrics\\u003CFRE_ExperimentationUsageGroupCollection,msCombineStartHomeNTP\\u003COnStartupCoalesce,msEEProactiveHistory\\u003Ceeproactivehistory,msEdgeAddWebCapturetoCollections\\u003CAddWebCapturesToCollections2,msEdgeContinuousAutofillImport\\u003CContinuosImportModuleRollout,"
		"msEdgeContinuousChromeImport\\u003CContinuosImportModuleRollout,msEdgeContinuousCookiesImport\\u003CContinuosImportModuleRollout,msEdgeContinuousHistoryImport\\u003CContinuosImportModuleRollout,msEdgeContinuousMigrationLogging\\u003CContinuosImportModuleRollout,msEdgeContinuousPasswordImport\\u003CContinuosImportModuleRollout,msEdgeContinuousPaymentsImport\\u003CContinuosImportModuleRollout,msEdgeEnableDiagnosticEventHardFaults\\u003CEdgeStartupMetricsHardFaultCount,"
		"msEdgeEnableNurturingFramework\\u003CNurturingFrameworkRollout,msEdgeFaviconService\\u003CHistoryAndOpenTabsSync,msEdgeFeedbackAadcCheck\\u003CAADCComplianceUI,msEdgeFeedbackShowRecreateButton\\u003CEdgeFeedbackShowRecreateButton,msEdgeFreNTPLayoutAndChoiceDefaultOverrideTree\\u003CFRE_NTPLayoutAndChoiceDecisionTree,msEdgeFreSecondDevice\\u003CFRE_SecondDevice,msEdgeOnRampReimport\\u003CSpartanReimport,msEdgeOnRampShowWhatsNew\\u003CEdgeOnRampShowVersionWhatsNew,"
		"msEdgePasswordImport\\u003CPasswordImportCSV,msEdgeSendTabToSelf\\u003CEdgeSendTabToSelf,msEdgeServerSideShopping\\u003CEdgeShoppingV2Phase1,msEdgeShoppingAutoShowControlForFeature\\u003CEdgeShoppingPerFeatureAutoShow,msEdgeShoppingExpressCheckoutFillDetails\\u003CEdgeShoppingExpressCheckoutCFR,msEdgeShoppingSupressPriceComparisonAutoShow\\u003CEdgeShoppingPriceCompareIntelligentTriggering,msEdgeSyncHistory\\u003CHistoryAndOpenTabsSync,msEdgeSyncOpenTabs\\u003CHistoryAndOpenTabsSync,"
		"msEdgeUseByteSizeBatching\\u003CHistoryAndOpenTabsSync,msEdgeWebCaptureOOUIExperiment\\u003CEdgeWebCaptureOOUIExperiment,msEnableBingNewTabBackButtonFocus\\u003CBingNewTabBackButton,msEnableReactBingRequest\\u003CBingLocation,msEnableReactPermissionRequest\\u003CBingLocation,msFlyoutDefaultHandlerForPDFOpen\\u003CpdfDefaultsFlyout,msForceTelemetrySampling\\u003CTelemetryPopSampleSampling,msForeignSessionsPage\\u003CHistoryAndOpenTabsSync,"
		"msGrowthInfraLaunchSourceLogging\\u003CGrowthInfraLaunchSourceLogging,msHistogramsGovernanceList\\u003COverrideHistograms,msLogTestUniformDistributionHistogram\\u003CTelemetryPopSampleSampling,msNurturingStandardLaunch\\u003CRecommendedSettingsdialogStableCFR,msNurturingStandardLaunchWithDSE\\u003CRecommendedSettingsdialogStableCFR,msOpenOfficeDocumentsInWebViewer\\u003CQuickView,msOpusFormat\\u003COnlineVoicesOpus,msPdfReportDiagnostics\\u003CPdfDiagnostics,"
		"msPermaEdgeOnNthNeedEdgeTrigger\\u003CPermaEdgeOnNthNeedEdge,msPromptDefaultHandlerForPDF\\u003CpdfDefaults,msRaisePluginProcessLimit\\u003CPdfRaisePPAPIProcessLimit,msShoppingAutoShowLowerPrices\\u003CEdgeShoppingPriceCompareIntelligentTriggering,msShoppingExp14\\u003CEdgeShoppingPriceCompareIntelligentTriggering,msShowPermaEdgeInterstitial\\u003CPermaEdge_optout_interstitial,msSidebarSearchForImageAfterSearchWebFor\\u003CImageSearchInSidebar,"
		"msSmartScreenBrowserDnsLookups\\u003CSmartScreenDnsOverHttps,msSpeechRecognition\\u003CSpeechRecognition,msSyncMicrosoftUserId\\u003CSyncMicrosoftUserIdWithFeedsInTaskbar,msSyncSessionOptimizations\\u003CHistoryAndOpenTabsSync,msUACompatibilityFix\\u003CUACompatibilityFix,msUseHttpsForDownloadingCrx\\u003CCFR UseHttpsForDownload\"}", 
		LAST);

	web_add_header("X-AFS-CV", 
		"tgC49zWKKjbr8iCY0i6lY4");

	web_add_header("X-AFS-ClientInfo", 
		"platform=Windows; os=Windows NT; osVer=10.0.19043; app=Microsoft Edge; appVer=94.0.992.38; appChannel=stable;");

	web_url("homeCloud", 
		"URL=https://edge.activity.windows.com/v2/feeds/me/settings/homeCloud", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("www.youtube.com", 
		"URL=https://www.youtube.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/s/desktop/18284868/jsbin/desktop_polymer.vflset/desktop_polymer.js", ENDITEM, 
		"Url=/s/desktop/18284868/jsbin/web-animations-next-lite.min.vflset/web-animations-next-lite.min.js", ENDITEM, 
		"Url=/s/desktop/18284868/cssbin/www-main-desktop-home-page-skeleton.css", ENDITEM, 
		"Url=/s/desktop/18284868/jsbin/webcomponents-sd.vflset/webcomponents-sd.js", ENDITEM, 
		"Url=/s/desktop/18284868/jsbin/custom-elements-es5-adapter.vflset/custom-elements-es5-adapter.js", ENDITEM, 
		"Url=/s/desktop/18284868/cssbin/www-onepick.css", ENDITEM, 
		"Url=/s/desktop/18284868/cssbin/www-main-desktop-watch-page-skeleton.css", ENDITEM, 
		"Url=https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;500;700&family=YouTube+Sans:wght@300..900&display=swap", ENDITEM, 
		"Url=https://i.ytimg.com/vi/j9J7cjGU_jM/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLAir1sTjLQcfNZhZIqlqJyJuM-F0g", ENDITEM, 
		"Url=https://i.ytimg.com/vi/EsMSi0CF3jE/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDG9tZpn7a1n5MOccqHyI1yPMZ-_A", ENDITEM, 
		"Url=https://www.gstatic.com/youtube/img/promos/growth/3300985d3fcd055eee35a3388df0b49c62bb96bb287cc11a49c99b0617ccdc77_2560x520.png", ENDITEM, 
		"Url=https://www.google.co.in/pagead/lvz?evtid=AKB78ch5T0tQzOh7o-wjadFKOLRPpdPKUYwMoz6VzzlmaWCVb0xJ7AYyodh3Zaci1Mg1zkuMK1DY-R4iKZ1Bze584OFN7ElvaQ&req_ts=1633321817&pg=MainAppBootstrap%3AHome&az=1&sigh=AKFpyYWht1oO4p5AI1kmdnYiSmXWuWLFqA", ENDITEM, 
		"Url=https://i.ytimg.com/vi/pRbxlpvXw2s/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLC-89dNt9_dGfM3Oq_WJorgsbMyWQ", ENDITEM, 
		"Url=https://i.ytimg.com/vi/LG19ZG7XQZs/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLBfnFSosyyyUqbdukz52LeV0IpN4A", ENDITEM, 
		"Url=https://i.ytimg.com/vi/PsWQa2dd7H0/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLAaS4jnRhosIpguzBjUFwBqSaFg3Q", ENDITEM, 
		"Url=https://www.google.com/pagead/lvz?evtid=AKB78ch5T0tQzOh7o-wjadFKOLRPpdPKUYwMoz6VzzlmaWCVb0xJ7AYyodh3Zaci1Mg1zkuMK1DY-R4iKZ1Bze584OFN7ElvaQ&req_ts=1633321817&pg=MainAppBootstrap%3AHome&az=1&sigh=AKFpyYWht1oO4p5AI1kmdnYiSmXWuWLFqA", ENDITEM, 
		"Url=https://i.ytimg.com/vi/j3KowCpjK1I/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLAzjifTDbqYJysjF--o0xM5ewdZdA", ENDITEM, 
		"Url=https://www.gstatic.com/youtube/img/promos/growth/50f85885003c94b4a70bbe7221c7985e4cb1c55f0e43f78f849824c20ccc58b5_640x48.png", ENDITEM, 
		"Url=https://yt3.ggpht.com/ytc/AKedOLSLoqP3pxh4nxmkaZvxhgFVxvzIhTctHsltCsbqKg=s68-c-k-c0x00ffffff-no-rj", ENDITEM, 
		"Url=https://yt3.ggpht.com/ytc/AKedOLQtdriwxzeBde7W9ZDf2KYGtxEz-7RkzWhgemBm=s68-c-k-c0x00ffffff-no-rj", ENDITEM, 
		"Url=https://yt3.ggpht.com/ytc/AKedOLS5DwL15DjvEUi7a36RXAgvHUKLCAEFm8Uaw1pQ-g=s68-c-k-c0x00ffffff-no-rj", ENDITEM, 
		"Url=https://yt3.ggpht.com/Nox2EXPVCOzTxp-ol6smEivHr6esxd27o_E_26RlHIE9esM7Xcd391XrZbtBLg7TgH4kDAYRMA=s68-c-k-c0x00ffffff-no-rj", ENDITEM, 
		"Url=https://i.ytimg.com/vi/orYf6VDtj_k/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDgglhc3dnaFFIPHqWJ7Jn2p2REbg", ENDITEM, 
		"Url=https://yt3.ggpht.com/ytc/AKedOLQEtaXOYwh87BvVOp7-nLoiZNlLuW-X8PN37OwyV8c=s68-c-k-c0x00ffffff-no-rj", ENDITEM, 
		"Url=https://i.ytimg.com/vi/sBBFSuHATmw/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLAWQUfnsu5-jJI1fao5Q56a1Lcszg", ENDITEM, 
		"Url=https://i.ytimg.com/vi/sUoVswDWNCQ/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLBJDsgIkvisQBzJlVWDRNua904vGQ", ENDITEM, 
		"Url=https://i.ytimg.com/vi/nks4U0yUGas/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDARhpHdUqeUd_hu2AmOM8KYZ_3Hg", ENDITEM, 
		"Url=https://i.ytimg.com/vi/JngV9Ix5hnk/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLA8stAWHD5FiNunp-TIiJX4K886wQ", ENDITEM, 
		"Url=https://i.ytimg.com/vi/ud1rUsqcqj0/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDaovrwLqj_E8jcJcpsvrqTlz7JoA", ENDITEM, 
		"Url=https://i.ytimg.com/vi/1--qqQrimMA/hqdefault.jpg?sqp=-oaymwEcCOADEI4CSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLCtwCXhZ3xR3RDshRvmPZhM2Gb-Yg", ENDITEM, 
		"Url=https://i.ytimg.com/vi/VuCHCFTyskk/hqdefault.jpg?sqp=-oaymwEcCOADEI4CSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLC0NC48ibn844AyoOJ5nQN_03Q86A", ENDITEM, 
		"Url=https://i.ytimg.com/vi/1eYZ5WulRBk/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLAzxdIhb9LGgP240m7w2UMMY-DTZA", ENDITEM, 
		"Url=https://i.ytimg.com/vi/MU1KlsgYd5Q/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLByRpqNf3sTSRSXvoF4OohZy2QB0Q", ENDITEM, 
		"Url=https://i.ytimg.com/vi/gvyUuxdRdR4/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDcBTtuu3J65Pz2bspKXzcEMsuzcA", ENDITEM, 
		"Url=https://i.ytimg.com/vi/cjjofxNQshM/hqdefault.jpg?sqp=-oaymwEcCOADEI4CSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDfKrKmFSt5ebottuHsHbKEls-PLQ", ENDITEM, 
		"Url=https://i.ytimg.com/vi/tO0lt8agv98/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLBvgCRkDUQkyLgmlhcmtCNNCRaVsw", ENDITEM, 
		"Url=https://i.ytimg.com/vi/-93FYeJBKDQ/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLCc04ZJbI7muimDoZCZg0lN3iF5kw", ENDITEM, 
		"Url=https://i.ytimg.com/vi/SnvT9xPPldo/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDk68Fhn99JWsT_OKWau207y_YySA", ENDITEM, 
		"Url=https://i.ytimg.com/vi/-I9hIXRjXtE/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLA7Qlyh6RD_hb_rrOt3OaQmoxz2vg", ENDITEM, 
		"Url=https://i.ytimg.com/vi/Dwqwgf23NlU/hq720_live.jpg?sqp=CMiG6ooG-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLCV_WqnMb6RN3ckp1t0waLz2L8GxA", ENDITEM, 
		"Url=https://i.ytimg.com/vi/W8eix6fM59g/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLChZpj6MhuW8IXgzbP8xCvoZWRf9A", ENDITEM, 
		"Url=https://i.ytimg.com/vi/CrHWF7YD0IY/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLCrNSsTDXc3QXCSnAyDXPe-IwPOtg", ENDITEM, 
		"Url=https://i.ytimg.com/vi/g1KTGM6YgoQ/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLB8nlseTe9HgdbhvtH6jx4iA_WSqw", ENDITEM, 
		"Url=https://i.ytimg.com/vi/4sSl4UgyjHw/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLAv70XM9w3CG9VgRq4ZrfoVg4YwEQ", ENDITEM, 
		"Url=https://www.gstatic.com/cv/js/sender/v1/cast_sender.js", ENDITEM, 
		"Url=https://i.ytimg.com/vi/w4ClQO0FFQg/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDOIH4BUTEROcrxjfWOnhUho6BsHQ", ENDITEM, 
		"Url=https://i.ytimg.com/vi/7htUqA1uDCU/hqdefault.jpg?sqp=-oaymwEcCOADEI4CSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDrQEBI2weK8fanJMnTWd7a6hvwOA", ENDITEM, 
		"Url=https://i.ytimg.com/vi/bi5PhlIQpwU/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDLYVZCLygsb84jArDAXKk_8ZVhiQ", ENDITEM, 
		"Url=https://i.ytimg.com/vi/BDaCRoi0Zxw/hqdefault.jpg?sqp=-oaymwEcCOADEI4CSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLCjl6KdzRTg9pjH5Z37ZM3nI9yyFA", ENDITEM, 
		"Url=https://i.ytimg.com/vi/lX3vT_Gm_HE/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLBzRfvSeWD2xGt8jmXUgWOkz6o7kQ", ENDITEM, 
		"Url=https://i.ytimg.com/vi/4J0pg1LmhQg/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLBqLZG6NxjAiAvq_MCIT9QBhl_PHg", ENDITEM, 
		"Url=https://static.doubleclick.net/instream/ad_status.js", ENDITEM, 
		"Url=https://i.ytimg.com/vi/3eJMovcItXg/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLBC3RO4mbWiSairdWYpyabAwYMKlA", ENDITEM, 
		"Url=https://i.ytimg.com/vi/UAaH9CFlHwc/hqdefault.jpg?sqp=-oaymwEcCOADEI4CSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLCUB6a0YIsNp7IJB1OvdS3Y9slE_g", ENDITEM, 
		"Url=https://i.ytimg.com/vi/s58rO7eSWLc/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLAzAEKGs62XowQYlDv7ymG_NeAQFw", ENDITEM, 
		"Url=https://i.ytimg.com/vi/9LrQ7F2l-ss/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLDfzD_Ay4j0RWsIbsprv4a2cM7gGQ", ENDITEM, 
		"Url=https://i.ytimg.com/vi/DB3D-mtWR0c/hq720.jpg?sqp=-oaymwEcCNAFEJQDSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLCpcdsVWMt66_9r-sOxEdVLcuqp_w", ENDITEM, 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("X-AFS-CV", 
		"08NWdpcyboJWF2YeOAoiyO");

	web_add_header("X-AFS-ClientInfo", 
		"platform=Windows; os=Windows NT; osVer=10.0.19043; app=Microsoft Edge; appVer=94.0.992.38; appChannel=stable;");

	web_custom_request("command", 
		"URL=https://edge.activity.windows.com/v1/feeds/me/syncEntities/command/?client=Chromium&client_id=kwCR2K%2FiVOxezc1selhFsA%3D%3D", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/vnd.google.octet-stream-compressible", 
		"Referer=", 
		"Snapshot=t5.inf", 
		"ContentEncoding=gzip", 
		"Mode=HTML", 
		"EncType=application/octet-stream", 
		"BodyBinary=\n\\x18kwCR2K/iVOxezc1selhFsA==\\x10Z\\x18\\x02*O\\x12\\x04\\x08\\x00\\x10\\x01\\x18\\x012\\x1E\\x08\\x9A\\xB7\t\\x12\\x08\\x9C\\xD9\\x8CI|\\x01\\x00\\x00*\\x0E\\x10\\x00\\x18\\x01 \\x00(\\x020\\x008\\x00@\\x002\\x1E\\x08\\x81\\xF5\\x02\\x12\\x08\\x9C\\xD9\\x8CI|\\x01\\x00\\x00*\\x0E\\x10\\x00\\x18\\x01 \\x00(\\x040\\x008\\x00@\\x00H\\x0CP\\x00\\xC0>\\x01:\\x1FProductionEnvironmentDefinitionR1\n\\x02\\x08\\x05\n\\x02\\x08\t\n\\x02\\x08\n\n\\x10*\\x0E\\x08\\x9A\\xB7\th\\x00x\\xFA\r"
		"\\x90\\x01\\x81\\xF5\\x02\n\\x0B*\t\\x08\\x81\\xF5\\x02h\\x00x\\xF6\\x05\\x10\\x01\\x18\\x00 \\x00Z\\x05\n\\x03101b 00000000000000000000000000000000j\\x02\\x10\\x00r\\x1Cchr:kwCR2K/iVOxezc1selhFsA==", 
		LAST);

	web_add_auto_header("Sec-Fetch-Site", 
		"cross-site");

	web_url("generate_204", 
		"URL=https://i.ytimg.com/generate_204", 
		"Resource=0", 
		"Referer=https://www.youtube.com/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_cookie("MUID=1388F6EA3DE966F7093EE67B3C4167EE; DOMAIN=www.bing.com");

	web_add_cookie("MUIDB=1388F6EA3DE966F7093EE67B3C4167EE; DOMAIN=www.bing.com");

	web_add_cookie("_EDGE_V=1; DOMAIN=www.bing.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=www.bing.com");

	web_add_cookie("SRCHUID=V=2&GUID=A6A212392318447CBB54A921B1D63A17&dmnchg=1; DOMAIN=www.bing.com");

	web_add_cookie("ANON=A=859765435557B4D533FF647AFFFFFFFF; DOMAIN=www.bing.com");

	web_add_cookie("_clck=2kbib1|1|ev7|0; DOMAIN=www.bing.com");

	web_add_cookie("ABDEF=V=13&ABDV=13&MRNB=1633153616959&MRB=0; DOMAIN=www.bing.com");

	web_add_cookie("_U=1AimpSL46Yxga3jsLe203deqpQ5YAA8olP-XqfnnA-NTLPsPaqmBoxu4osshcV9gAaLB8Wdf7Y_hxNB2p1YQ2_P5rIahiYQEqFU3IQzivXJYUHqyax3ZrTd6kB5SSVNrewnC5EVhdkOugjqrEbKJJn8flC81JCiwTyILVShu1iBB_dZXyndlAVg3xHkzsuTXXjH2JsNTf7aVgUQ4evUViEA; DOMAIN=www.bing.com");

	web_add_cookie("SRCHUSR=DOB=20210812&T=1633321513000; DOMAIN=www.bing.com");

	web_add_cookie("SRCHHPGUSR=SRCHLANG=en&BRW=XW&BRH=M&CW=1536&CH=754&SW=1536&SH=864&DPR=1.25&UTC=330&DM=1&HV=1633321513&EXLTT=3; DOMAIN=www.bing.com");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Mesh-Client-Arch", 
		"x86_64");

	web_add_header("Sec-Mesh-Client-Edge-Channel", 
		"stable");

	web_add_header("Sec-Mesh-Client-Edge-Version", 
		"94.0.992.38");

	web_add_header("Sec-Mesh-Client-OS", 
		"Windows");

	web_add_header("Sec-Mesh-Client-OS-Version", 
		"10.0.19043");

	web_add_header("Sec-Mesh-Client-WebView", 
		"0");

	web_add_header("X-Search-RPSToken", 
		"t=EwDIAgALBAAUWkziSC7RbDJKS1VkhugDegv7L0eAAHJsuVf28Btmx/MKeXbm6CUKbynmZIuEYJ76eJo51T4pPtvKX5ap+ZgpKgnDAyP+GvnVSXAIPPVAzVW1nvuv7xMnILEUSoIhQYH1AEET3+B+VOumztfY4LCPpzv37IO8pNfis6Qrl8u2V2ragufH/3wPtx3yvDRhra07DHQItvJjA2YAAAjE837JmSZLEBgCIFQkkalHeC9U6tE3huSNLbWBoEvvKoAysnWgilw48tDNDtA4Gn/w03/pwGBf+YVzXkh5EB9DLf2zih7YQ2bH3GZlCkboboKzKWZSYi4hoMo9XRiP2FTQxV1xpuUm9lnN9UIAXTYum75f3h3L9lFazhKTsIYpuzgQsRpJkgBhstdHl+t6eshfcIFDxMwN7r+pfPxxar4M/l1cavZUpX8cSNtC+SuHNF4IphO3SJQLGlQQY0CabLO6rMuWKLJZ1k7JesBxwmj8m28/"
		"gBnJv83S93pbcjBf7FGk8N6M00tLvU8fJG9eBhBEtIHCug/yi8xB1150wqASM2GYKiHP2KlwV4r1gL+xGj49q7dnsS8EDj6ZCGtGmg59IJzUa1NelTA8jRZGb/rv9iSjvLqAAQUGWoxyTFUmXg//nqfOWOxIG+J8gy2tLwrkPNvJfGKlQ15zIpy3OZyA6iyBuNKbT5Cv5/1qFJGP7B3o78ygCDwnGMMYlDBE5rv+m8e4w6TvH47zLfeCzIr1oexvpT2yH8zSJJILio5yw4wgsA+A4H/O1KvpBsP3PZdTE3C1FmOgaQpKW4eMWinFdqChvGTM0f66ID9QbqK6SYFmFEZqsZ3uWiE68WX7qb9BXiB7M3P3gRB0dcbaFvYWxJcq+0/6XbybmSH8+NkfNULpiVa2MKz2EsyL9pGmQNQOEg+t7xuDxVOdi4aV/upoEpdUAg==&p=");

	web_url("signin", 
		"URL=https://www.bing.com/fd/auth/signin?&action=header&provider=windows_live_id&save_token=0", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("X-AFS-ClientInfo", 
		"platform=Windows; os=Windows NT; osVer=10.0.19043; app=Microsoft Edge; appVer=94.0.992.38");

	web_custom_request("subscriptions", 
		"URL=https://edge.activity.windows.com/v2/feeds/me/subscriptions", 
		"Method=POST", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"channelurl\":\"https://wns2-sg2p.notify.windows.com/w/?token=BQYAAACQ4U%2fuq1hmlsFpd7f2PX3KNnVJMEWcs2MfCfGziZCDPJf2JaO9M37vRAo143umlsR14hSPCKEg63rmDYjfcT69FlTwxsjgK%2fI%2bM%2fE05cHf3h22xSFCkWY1%2bue%2bfIUxGeyWEdg56twi1WB%2fWulDM38WF%2fQuWmHFB62mbKwrCnE2yZCNcjqfOyO5BrgLmLU5Fu6vA8c5uyBUCcQkKRv9IHSqlEUOLcV8t2CISM2Se1KoI9XtDBUcmV8EXf4qALTDBYE%3d\",\"deviceId\":\"chr:kwCR2K/iVOxezc1selhFsA==\",\"publisherFilters\":[{\"activityTypes\":[71,82],\"application\":\"edge.activity.windows.com\",\""
		"notificationType\":\"notificationOnly\",\"platform\":\"host\"}]}", 
		LAST);

	web_add_auto_header("Sec-Fetch-Site", 
		"cross-site");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"iframe");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(5);

	web_url("ServiceLogin", 
		"URL=https://accounts.google.com/ServiceLogin?service=youtube&uilel=3&passive=true&continue=https%3A%2F%2Fwww.youtube.com%2Fsignin%3Faction_handle_signin%3Dtrue%26app%3Ddesktop%26hl%3Den%26next%3D%252Fsignin_passive%26feature%3Dpassive&hl=en", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.youtube.com/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://fonts.gstatic.com/s/roboto/v29/KFOmCnqEu92Fr1Mu4mxK.woff2", "Referer=https://fonts.googleapis.com/", ENDITEM, 
		"Url=https://edge.microsoft.com/autofillservice/v1/pages/ChNDaHJvbWUvOTQuMC40NjA2LjcxEhAJPMqv4xTphZsSBQ3xo1vj?alt=proto", "Referer=", ENDITEM, 
		"Url=https://fonts.gstatic.com/s/roboto/v29/KFOlCnqEu92Fr1MmEU9fBBc4.woff2", "Referer=https://fonts.googleapis.com/", ENDITEM, 
		"Url=https://fonts.gstatic.com/s/youtubesans/v8/Qw38ZQNGEDjaO2m6tqIqX5E-AVS5_rSejo46_PCTRspJ0OosolrBEJL3HO_T7fE.woff2", "Referer=https://fonts.googleapis.com/", ENDITEM, 
		"Url=https://fonts.gstatic.com/s/roboto/v29/KFOlCnqEu92Fr1MmWUlfBBc4.woff2", "Referer=https://fonts.googleapis.com/", ENDITEM, 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Mesh-Client-Arch", 
		"x86_64");

	web_add_header("Sec-Mesh-Client-Edge-Channel", 
		"stable");

	web_add_header("Sec-Mesh-Client-Edge-Version", 
		"94.0.992.38");

	web_add_header("Sec-Mesh-Client-OS", 
		"Windows");

	web_add_header("Sec-Mesh-Client-OS-Version", 
		"10.0.19043");

	web_add_header("Sec-Mesh-Client-WebView", 
		"0");

	web_add_header("X-Microsoft-Update-AppId", 
		"ohckeflnhegojcjlcpbfpciadgikcohk,oankkpibpaokgecfckkdkgaoafllipag,fppmbhmldokgmleojlplaaodlkibgikh,bogljiopgniojgccjbgnjehadfndkghp,jbfaflocpnkhbgcijpkiafdpbjkedane,ojblfafjmiikbkepnnolpgbbhejhlcim,ahmaebgpfccdhgidjaidaoojjcijckba,mkcgfaeepibomfapiapjaceihcojnphg,lfmeghnikdkbonehgjihjebgioakijgn");

	web_add_header("X-Microsoft-Update-Interactivity", 
		"bg");

	web_add_header("X-Microsoft-Update-Updater", 
		"msedge-94.0.992.38");

	web_custom_request("update", 
		"URL=https://edge.microsoft.com/componentupdater/api/v1/update?cup2key=4:906110854&cup2hreq=85a16f65a0d3941ede86ac737f2c422e88d1be15861fc552d9d1a2c96af0b120", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"request\":{\"@os\":\"win\",\"@updater\":\"msedge\",\"acceptformat\":\"crx2,crx3\",\"app\":[{\"appid\":\"ohckeflnhegojcjlcpbfpciadgikcohk\",\"brand\":\"INBX\",\"cohort\":\"rrf@0.27\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.26123BEF7D73536450862D2C4D44963D720AA80B6FC2D8496F559CB9C1FDEB00\"}]},\"ping\":{\"r\":-2},\"targetingattributes\":{\"AppCohort\":\"rrf@0.27\",\"AppMajorVersion\":\"94\",\"AppRollout\":0.27,\"AppVersion\":\"94.0.992.38\",\"IsInternalUser\":false,\"Priority"
		"\":false,\"Updater\":\"Omaha\",\"UpdaterVersion\":\"1.3.151.27\"},\"updatecheck\":{},\"version\":\"0.0.1.4\"},{\"appid\":\"oankkpibpaokgecfckkdkgaoafllipag\",\"brand\":\"INBX\",\"cohort\":\"rrf@0.35\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.A672F2D8585AD6F2DADB3B00C6A2DCF8937449609B95ACA0411344AD2617C5D1\"}]},\"ping\":{\"r\":-2},\"targetingattributes\":{\"AppCohort\":\"rrf@0.35\",\"AppMajorVersion\":\"94\",\"AppRollout\":0.35,\"AppVersion\":\"94.0.992.38\",\"IsInternalUser\":false,"
		"\"Priority\":false,\"Updater\":\"Omaha\",\"UpdaterVersion\":\"1.3.151.27\"},\"updatecheck\":{},\"version\":\"6498.2021.8.1\"},{\"appid\":\"fppmbhmldokgmleojlplaaodlkibgikh\",\"brand\":\"INBX\",\"cohort\":\"rrf@0.41\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.02BE1BF447628CDC96AE2B6811BC38AC47CBB5059ABD6F31E9B2933F969A46AF\"}]},\"ping\":{\"r\":-2},\"targetingattributes\":{\"AppCohort\":\"rrf@0.41\",\"AppMajorVersion\":\"94\",\"AppRollout\":0.41,\"AppVersion\":\"94.0.992.38\",\""
		"IsInternalUser\":false,\"Priority\":false,\"Updater\":\"Omaha\",\"UpdaterVersion\":\"1.3.151.27\"},\"updatecheck\":{},\"version\":\"1.0.0.7\"},{\"appid\":\"bogljiopgniojgccjbgnjehadfndkghp\",\"brand\":\"INBX\",\"cohort\":\"rrf@0.78\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.CCE06140D787F0FEAD85CDA0BC6E0DA1F1202547441C80B0F3CD6DC33B3CE071\"}]},\"ping\":{\"r\":-2},\"targetingattributes\":{\"AppCohort\":\"rrf@0.78\",\"AppMajorVersion\":\"94\",\"AppRollout\":0.78,\"AppVersion\":\""
		"94.0.992.38\",\"IsInternalUser\":false,\"Priority\":false,\"Updater\":\"Omaha\",\"UpdaterVersion\":\"1.3.151.27\"},\"updatecheck\":{},\"version\":\"9.30.0\"},{\"appid\":\"jbfaflocpnkhbgcijpkiafdpbjkedane\",\"brand\":\"INBX\",\"cohort\":\"rrf@0.70\",\"enabled\":true,\"ping\":{\"r\":-2},\"targetingattributes\":{\"AppCohort\":\"rrf@0.70\",\"AppMajorVersion\":\"94\",\"AppRollout\":0.7,\"AppVersion\":\"94.0.992.38\",\"IsInternalUser\":false,\"Priority\":false,\"Updater\":\"Omaha\",\"UpdaterVersion\":\""
		"1.3.151.27\"},\"updatecheck\":{},\"version\":\"1.0.0.19\"},{\"appid\":\"ojblfafjmiikbkepnnolpgbbhejhlcim\",\"brand\":\"INBX\",\"cohort\":\"rrf@0.92\",\"enabled\":true,\"ping\":{\"r\":-2},\"targetingattributes\":{\"AppCohort\":\"rrf@0.92\",\"AppMajorVersion\":\"94\",\"AppRollout\":0.92,\"AppVersion\":\"94.0.992.38\",\"IsInternalUser\":false,\"Priority\":false,\"Updater\":\"Omaha\",\"UpdaterVersion\":\"1.3.151.27\"},\"updatecheck\":{},\"version\":\"4.10.2209.0\"},{\"appid\":\""
		"ahmaebgpfccdhgidjaidaoojjcijckba\",\"brand\":\"INBX\",\"cohort\":\"rrf@0.28\",\"enabled\":true,\"packages\":{\"package\":[{\"fp\":\"1.9AB1DC1C2C03AA5B274E583DC42891BC07DCCEEA577AC348940E112B48FA6006\"}]},\"ping\":{\"r\":-2},\"targetingattributes\":{\"AppCohort\":\"rrf@0.28\",\"AppMajorVersion\":\"94\",\"AppRollout\":0.28,\"AppVersion\":\"94.0.992.38\",\"IsInternalUser\":false,\"Priority\":false,\"Updater\":\"Omaha\",\"UpdaterVersion\":\"1.3.151.27\"},\"updatecheck\":{},\"version\":\"2.0.0.0\"},{\""
		"appid\":\"mkcgfaeepibomfapiapjaceihcojnphg\",\"brand\":\"INBX\",\"cohort\":\"rrf@0.99\",\"enabled\":true,\"ping\":{\"r\":-2},\"targetingattributes\":{\"AppCohort\":\"rrf@0.99\",\"AppMajorVersion\":\"94\",\"AppRollout\":0.99,\"AppVersion\":\"94.0.992.38\",\"IsInternalUser\":false,\"Priority\":false,\"Updater\":\"Omaha\",\"UpdaterVersion\":\"1.3.151.27\"},\"updatecheck\":{},\"version\":\"0.0.0.0\"},{\"appid\":\"lfmeghnikdkbonehgjihjebgioakijgn\",\"brand\":\"INBX\",\"cohort\":\"rrf@0.46\",\"enabled\""
		":true,\"packages\":{\"package\":[{\"fp\":\"1.68715CA8CDD03437049D6D9D2CEB47584B886A7807BC9B2B483E3FAA174694DF\"}]},\"ping\":{\"r\":-2},\"targetingattributes\":{\"AppCohort\":\"rrf@0.46\",\"AppMajorVersion\":\"94\",\"AppRollout\":0.46,\"AppVersion\":\"94.0.992.38\",\"IsInternalUser\":false,\"Priority\":false,\"Updater\":\"Omaha\",\"UpdaterVersion\":\"1.3.151.27\"},\"updatecheck\":{},\"version\":\"1.0.6.0\"}],\"arch\":\"x64\",\"dedup\":\"cr\",\"domainjoined\":false,\"hw\":{\"physmemory\":8},\"lang\""
		":\"en-US\",\"nacl_arch\":\"x86-64\",\"os\":{\"arch\":\"x86_64\",\"platform\":\"Windows\",\"version\":\"10.0.19043.1237\"},\"prodversion\":\"94.0.992.38\",\"protocol\":\"3.1\",\"requestid\":\"{0e440aca-2646-4d61-97a4-17d08965f84d}\",\"sessionid\":\"{2f12a5fa-15b4-49fa-9e82-cb7f910e278f}\",\"updater\":{\"autoupdatecheckenabled\":true,\"ismachine\":true,\"lastchecked\":0,\"laststarted\":0,\"name\":\"Omaha\",\"updatepolicy\":-1,\"version\":\"1.3.151.27\"},\"updaterversion\":\"94.0.992.38\"}}", 
		LAST);

	return 0;
}