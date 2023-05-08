package Tarea5_3;
import static Tarea5_3.Tokens.*;
%%
%class Lexer
%type Tokens
L=[a-zA-Z_]+
N=[0-9]+
espacio=[ ,\t,\r]+
parraf = [\n]+
Func = ["()"]
GuionBajo = "_"
%{
    public String lexeme;
%}
%%
{espacio} {return Espacio;}
{parraf} {return Parrafo;}
":" |
"." |
";" |
"," {return Delimitador;}

"+" |
"-" |
"*" | "**" | 
"/" |
"%" |
"^" {return OperadorAritmetico;}

"=" {return Asignacion;}

"!" |
"&&" |
"||" {return OperadorBooleano;}

"<" | "<=" |
">" | ">=" |
"==" |
"!=" {return Comparador;}

"(" |
")" |
"{" |
"[" |
"]" |
"}" {return Delimitador;}

(-?{N}+) {return NumeroEntero;}
(-?{N}+ \. {N}+) | (\. {N}+) {return Numerodecimal;}
(\"[^\n\t\r]*\") | (\'[^\n\t\r]*\') {return Palabras;}

("/""/") | 
("/""*") | 
("#") |
("%"{L}) |
("*""/") {return Comentario;}

int | Int | INT | 
float | Float | Float |
char | Char | Char |
double | Double | DOUBLE |
void | Void | VOID |
long | Long | LONG | 
unsigned | Unsigned | UNSIGNED |
signed | Signed | SIGNED |
const | Const | CONST |
struct | Struct | STRUCT |
auto | Auto | AUTO |
global | Global | GLOBAL |
static | Static | STATIC {return Literal;}

and | And | AND |
as | As | AS |
assert | Assert | ASSERT |
break | Break | BREAK | 
class | Class | CLASS |
clear | Clear | Clear |
clc | Clc | CLC |
case | Case | CASE |
catch | Catch | CATCH |
cont | Cont | CONT |
def | Def | DEF |
default | Default | DEFAULT |
del | Del | DEL |
do | Do | DO |
elif | Elif | ELIF |
else | Else | ELSE |
enum | Enum | ENUM |
except | Except | EXCEPT |
extern | Extern | EXTERN |
finally | Finally | FINALLY |
false | False | FALSE |
for | For | FOR |
from | From | FROM |
goto | Goto | GOTO |
if | IF | If |
import | Import | IMPORT |
in | In | IN |
include | Include | INCLUDE |
is | Is | IS |
lambda | Lambda | LAMBDA |
nonlocal | Nonlocal | NONLOCAl |
none | None | NONE |
null | Null | NULL |
not | Not | NOT |
or | Or | OR |
pass | Pass | PASS |
range | Range | RANGE |
raise | Raise | RAISE |
register | Register | REGISTER |
return | Return | RETURN |
sizeof | Sizeof | SIZEOF |
switch | Switch | SWITCH |
typedef | Typedef | TYPEDEF | 
true | True | TRUE | 
try | Try | TRY |
union | Union | UNION |
volatile | Volatile | VOLATILE |
with | With | WITH |
while | While | WHILE |
yield | Yield | YIELD |
printf | Printf | PRINTF |
println | Println | PRINTLN |
print | Print | PRINT |
cout | Cout | COUT |
endl | Endl | ENDL |
axis | Axis | AXIS |
text | Text | TEXT |
title | Title | TITLE |
figure | Figure | FIGURE |
plot | Plot | PLOT |
plot3 | Plot3 | PLOT3 |
sqrt | Sqrt | SQRT |
on | On | ON |
patch | Patch | PATCH |
off | Off | OFF |
input | Input | INPUT |
disp | Disp | DISP |
quiver | Quiver | QUIVER |
label | Label | LABEL |
grid | Grid | GRID |
length | Length | LENGTH |
end | End | END |
"<<" |
">>" {return Reservadas;}
{L}({L}|{N}|{GuionBajo})* {return Variable;}
 . {return ERROR;}