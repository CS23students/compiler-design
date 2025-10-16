%{
#include "variable.tab.h"
%}

%%
[a-zA-Z]    { return LETTER; }
[0-9]       { return DIGIT; }
\n          { return 0; }
.           { return 0; }
%%

int yywrap() { return 1; }
