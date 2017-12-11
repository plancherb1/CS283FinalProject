MATLAB="/usr/local/MATLAB/R2017a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/brian/.matlab/R2017a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for meanShiftLABXY" > meanShiftLABXY_mex.mki
echo "CC=$CC" >> meanShiftLABXY_mex.mki
echo "CFLAGS=$CFLAGS" >> meanShiftLABXY_mex.mki
echo "CLIBS=$CLIBS" >> meanShiftLABXY_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> meanShiftLABXY_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> meanShiftLABXY_mex.mki
echo "CXX=$CXX" >> meanShiftLABXY_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> meanShiftLABXY_mex.mki
echo "CXXLIBS=$CXXLIBS" >> meanShiftLABXY_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> meanShiftLABXY_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> meanShiftLABXY_mex.mki
echo "LDFLAGS=$LDFLAGS" >> meanShiftLABXY_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> meanShiftLABXY_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> meanShiftLABXY_mex.mki
echo "Arch=$Arch" >> meanShiftLABXY_mex.mki
echo "LD=$LD" >> meanShiftLABXY_mex.mki
echo OMPFLAGS= >> meanShiftLABXY_mex.mki
echo OMPLINKFLAGS= >> meanShiftLABXY_mex.mki
echo "EMC_COMPILER=gcc" >> meanShiftLABXY_mex.mki
echo "EMC_CONFIG=optim" >> meanShiftLABXY_mex.mki
"/usr/local/MATLAB/R2017a/bin/glnxa64/gmake" -B -f meanShiftLABXY_mex.mk
