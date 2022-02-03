/* if (boolean expression) {

}
else {

}

^ This is the notation.


if (bool exp) {

}
else if (bool exp) {

}
else if (bool exp) {

}
else {

}

^ In this notation if/elseif/else, each path is mutually exclusive, meaning you can only go down one path at a time.


if (bool exp) {

}
if (bool exp) {

}
if (bool exp) {

}
else {

}

^ Here branches 1, 2, and 3 are NOT mutually exclusive. Branches 3 and 4 are, however.

C's switch() statement is a conditional statement allowing enumeration of discrete cases instead of relying on boolean expressions. It is important to include a break statement under each case,
otherwise you will fall through the cases. For example:
int x = get_int("x: ");
switch(x) {
    case 5:
        printf("Five...");
    case 4:
        printf("Four...");
    case 3:
        printf("Three...");
    case 2:
        printf("Two...");
    case 1:
        printf("One...");
    default:
        printf("Blastoff!\n")
}

^^ If a user inputs "3", this will print "Three...Two...One...Blastoff!".

?: is another conditional statement (reskin of a short if else statement).
int x;
if (bool exp) {
    x = 5;
}
else {
    x = 6;
}

^^ This is the same as int x = (bool exp) ? 5 : 6.