@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=kalmanfilter_mex
set MEX_NAME=kalmanfilter_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2015b\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for kalmanfilter > kalmanfilter_mex.mki
echo COMPILER=%COMPILER%>> kalmanfilter_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> kalmanfilter_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> kalmanfilter_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> kalmanfilter_mex.mki
echo LINKER=%LINKER%>> kalmanfilter_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> kalmanfilter_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> kalmanfilter_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> kalmanfilter_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> kalmanfilter_mex.mki
echo BORLAND=%BORLAND%>> kalmanfilter_mex.mki
echo OMPFLAGS= >> kalmanfilter_mex.mki
echo OMPLINKFLAGS= >> kalmanfilter_mex.mki
echo EMC_COMPILER=lcc64>> kalmanfilter_mex.mki
echo EMC_CONFIG=optim>> kalmanfilter_mex.mki
"C:\Program Files\MATLAB\R2015b\bin\win64\gmake" -B -f kalmanfilter_mex.mk
