import std.stdio;

void main(){
// Print out information about integer types
    writefln("(%d) bool    min: %20d  max: %20d",    bool.sizeof,   bool.min,   bool.max);  
    writefln("(%d) ubyte   min: %20d  max: %20d",   ubyte.sizeof,  ubyte.min,  ubyte.max);  
    writefln("(%d) ushort  min: %20d  max: %20d",  ushort.sizeof, ushort.min, ushort.max);  
    writefln("(%d) uint    min: %20d  max: %20d",    uint.sizeof,   uint.min,   uint.max);  
    writefln("(%d) ulong   min: %20d  max: %20d\n", ulong.sizeof,  ulong.min,  ulong.max);    
    
    writefln("(%d) byte    min: %20d  max: %20d",    byte.sizeof,  byte.min,  byte.max);  
    writefln("(%d) short   min: %20d  max: %20d",   short.sizeof, short.min, short.max);    
    writefln("(%d) int     min: %20d  max: %20d",     int.sizeof,   int.min,   int.max);    
    writefln("(%d) long    min: %20d  max: %20d\n",  long.sizeof,  long.min,  long.max);    

    // Show information about floating-point types...
    writefln("(%d) float\t(%d) double\t(%d) real", float.sizeof,  double.sizeof,  real.sizeof);

    // Show information about character types...
    writefln("(%d) char\t(%d) wchar\t(%d) dchar", char.sizeof, wchar.sizeof, dchar.sizeof);
}	
