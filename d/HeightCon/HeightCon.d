import std.stdio;

void main() {
	immutable inchPerFoot = 12;
	immutable cmPerInch = 2.54;
	
	foreach (feet; 5 .. 7) {
		foreach (inches; 0 .. inchPerFoot){
		writeln(feet, "'", inches, "''\t",
		(feet * inchPerFoot + inches) * cmPerInch);
	}
}
}
