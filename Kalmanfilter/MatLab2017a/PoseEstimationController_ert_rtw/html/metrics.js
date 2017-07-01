function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtInf"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	size: 8};
	 this.metricsArray.var["rtInfF"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	size: 4};
	 this.metricsArray.var["rtMinusInf"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	size: 8};
	 this.metricsArray.var["rtMinusInfF"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	size: 4};
	 this.metricsArray.var["rtNaN"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	size: 8};
	 this.metricsArray.var["rtNaNF"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	size: 4};
	 this.metricsArray.fcn["rtGetInf"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rtGetInf.cpp",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["rtGetInfF"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rtGetInf.cpp",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetMinusInf"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rtGetInf.cpp",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["rtGetMinusInfF"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rtGetInf.cpp",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetNaN"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rtGetNaN.cpp",
	stack: 20,
	stackTotal: 20};
	 this.metricsArray.fcn["rtGetNaNF"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rtGetNaN.cpp",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtIsInf"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsInfF"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaN"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaNF"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_InitInfAndNaN"] = {file: "C:\\Users\\Philipp\\Desktop\\Masterprojekt\\Kalmanfilter\\MatLab2017a\\slprj\\ert\\_sharedutils\\rt_nonfinite.cpp",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="PoseEstimationController_metrics.html">Global Memory: 36(bytes) Maximum Stack: 20(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
