%module mincode
%{
#include "mincode.h"
%}

%include "std_vector.i"
%include "stdint.i"
%template(vectorUint32t) std::vector<uint32_t>;

%include "mincode.h"
