CC="/usr/bin/gcc"
                CXX="g++"
                CFLAGS="-fexceptions -fPIC -fno-omit-frame-pointer -pthread -DTARGET_API_VERSION=700   -D_GNU_SOURCE -DMATLAB_MEX_FILE "
                CXXFLAGS="-fexceptions -fPIC -fno-omit-frame-pointer -pthread -std=c++11 -DTARGET_API_VERSION=700   -D_GNU_SOURCE -DMATLAB_MEX_FILE "
                COPTIMFLAGS="-O -DNDEBUG"
                CXXOPTIMFLAGS="-O -DNDEBUG"
                CDEBUGFLAGS="-g"
                CXXDEBUGFLAGS="-g"
                LD="/usr/bin/gcc"
                LDXX="g++"
                LDFLAGS="-pthread -Wl,--no-undefined -Wl,-rpath-link,/usr/local/MATLAB/R2017a/bin/glnxa64 -shared  -L"/usr/local/MATLAB/R2017a/bin/glnxa64" -lmx -lmex -lmat -lm -lstdc++ -Wl,--version-script,"/usr/local/MATLAB/R2017a/extern/lib/glnxa64/mexFunction.map""
                LDDEBUGFLAGS="-g"
