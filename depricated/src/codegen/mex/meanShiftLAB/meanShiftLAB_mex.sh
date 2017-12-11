MATLAB="/usr/local/MATLAB/R2017a"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/brian/.matlab/R2017a"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for meanShiftLAB" > meanShiftLAB_mex.mki
echo "CC=$CC" >> meanShiftLAB_mex.mki
echo "CFLAGS=$CFLAGS" >> meanShiftLAB_mex.mki
echo "CLIBS=$CLIBS" >> meanShiftLAB_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> meanShiftLAB_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> meanShiftLAB_mex.mki
echo "CXX=$CXX" >> meanShiftLAB_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> meanShiftLAB_mex.mki
echo "CXXLIBS=$CXXLIBS" >> meanShiftLAB_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> meanShiftLAB_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> meanShiftLAB_mex.mki
echo "LDFLAGS=$LDFLAGS" >> meanShiftLAB_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> meanShiftLAB_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> meanShiftLAB_mex.mki
echo "Arch=$Arch" >> meanShiftLAB_mex.mki
echo "LD=$LD" >> meanShiftLAB_mex.mki
echo OMPFLAGS= >> meanShiftLAB_mex.mki
echo OMPLINKFLAGS= >> meanShiftLAB_mex.mki
echo "EMC_COMPILER=gcc" >> meanShiftLAB_mex.mki
echo "EMC_CONFIG=optim" >> meanShiftLAB_mex.mki
"/usr/local/MATLAB/R2017a/bin/glnxa64/gmake" -B -f meanShiftLAB_mex.mk
