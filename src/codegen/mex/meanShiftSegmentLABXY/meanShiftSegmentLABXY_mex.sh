MATLAB="/usr/local/MATLAB/R2017a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/brian/.matlab/R2017a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for meanShiftSegmentLABXY" > meanShiftSegmentLABXY_mex.mki
echo "CC=$CC" >> meanShiftSegmentLABXY_mex.mki
echo "CFLAGS=$CFLAGS" >> meanShiftSegmentLABXY_mex.mki
echo "CLIBS=$CLIBS" >> meanShiftSegmentLABXY_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> meanShiftSegmentLABXY_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> meanShiftSegmentLABXY_mex.mki
echo "CXX=$CXX" >> meanShiftSegmentLABXY_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> meanShiftSegmentLABXY_mex.mki
echo "CXXLIBS=$CXXLIBS" >> meanShiftSegmentLABXY_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> meanShiftSegmentLABXY_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> meanShiftSegmentLABXY_mex.mki
echo "LDFLAGS=$LDFLAGS" >> meanShiftSegmentLABXY_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> meanShiftSegmentLABXY_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> meanShiftSegmentLABXY_mex.mki
echo "Arch=$Arch" >> meanShiftSegmentLABXY_mex.mki
echo "LD=$LD" >> meanShiftSegmentLABXY_mex.mki
echo OMPFLAGS= >> meanShiftSegmentLABXY_mex.mki
echo OMPLINKFLAGS= >> meanShiftSegmentLABXY_mex.mki
echo "EMC_COMPILER=gcc" >> meanShiftSegmentLABXY_mex.mki
echo "EMC_CONFIG=optim" >> meanShiftSegmentLABXY_mex.mki
"/usr/local/MATLAB/R2017a/bin/glnxa64/gmake" -B -f meanShiftSegmentLABXY_mex.mk
