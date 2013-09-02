# A periodic table app that cycles through elements randomly
import random

answer = {"H" : "Hydrogen", "He" : "Helium", "Li" : "Lithium", "Be" : "Beryllium", "B" : "Boron", "C" : "Carbon", "N" : "Nitrogen", "O" : "Oxygen", "F" : "Fluorine", "Ne" : "Neon",
          "Na" : "Sodium", "Mg" : "Magnesium", "Al" : "Aluminum", "Si" : "Silicon", "P" : "Phosphorus", "S" : "Sulphur", "Cl" : "Chlorine", "Ar" : "Argon", "K" : "Potassium", "Ca" : "Calcium",
          "Sc" : "Scandium", "Ti" : "Titanium", "V" : "Vanadium", "Cr" : "Chromium", "Mn" : "Manganese", "Fe" : "Iron", "Co" : "Cobalt", "Ni" : "Nickel", "Cu" : "Copper", "Zn" : "Zinc",
          "Ga" : "Gallium", "Ge" : "Germanium", "As" : "Arsenic", "Se" : "Selenium", "Br" : "Bromine", "Kr" : "Krypton", "Rb" : "Rubidium", "Sr" : "Strontium", "Y" : "Yttrium",
          "Zr" : "Zirconium", "Nb" : "Niobium", "Mo" : "Molybdenum", "Tc" : "Technetium", "Ru" : "Ruthenium", "Rh" : "Rhodium", "Pd" : "Palladium", "Ag" : "Silver", "Cd" : "Cadmium",
          "In" : "Indium", "Sn" : "Tin", "Sb" : "Antimony", "Te" : "Tellurium", "I" : "Iodine", "Xe" : "Xenon", "Cs" : "Cesium", "Ba" : "Barium", "La" : "Lanthanum", "Ce" : "Cerium",
          "Pr" : "Praseodymium", "Nd" : "Neodymium", "Pm" : "Promethium", "Sm" : "Samarium", "Eu" : "Europium", "Gd" : "Gadolinium", "Tb" : "Terbium", "Dy" : "Dysprosium", "Ho" : "Holmium",
          "Er" : "Erbium", "Tm" : "Thulium", "Yb" : "Ytterbium", "Lu" : "Lutetium", "Hf" : "Hafnium", "Ta" : "Tantalum", "W" : "Tungsten", "Re" : "Rhenium", "Os" : "Osmium", "Ir" : "Iridium",
          "Pt" : "Platinum", "Au" : "Gold", "Hg" : "Mercury", "Tl" : "Thallium", "Pb" : "Lead", "Bi" : "Bismuth", "Po" : "Polonium", "At" : "Astatine", "Rn" : "Radon", "Fr" : "Francium",
          "Ra" : "Radium", "Ac": "Actinium", "Th" : "Thorium", "Pa" : "Protactinium", "U" : "Uranium", "Np" : "Neptunium", "Pu" : "Plutonium", "Am" : "Americium", "Cm" : "Curium", 
          "Bk" : "Berkelium", "Cf" : "Californium", "Es" : "Esteinium", "Fm" : "Fermium", "Md" : "Mendelevium", "No" : "Nobelium", "Lr" : "Lawrencium", "Rf" : "Rutherfordium", 
          "Db" : "Dubnium", "Sg" : "Seaborgium", "Bh" : "Bohrium", "Hs" : "Hassium", "Mt" : "Meitnerium", "Ds" : "Darmstadtium", "Rg" : "Roentgenium"}
          
symbol = ["H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga",   "Ge",
          "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm",
          "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U",
          "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg"]
          
attempt = None          
while attempt != "exit":
    rand_num = random.randint(0, len(symbol))
    rand_sym = symbol[rand_num]
    correct = answer[rand_sym]
    while attempt != correct and attempt != "exit" and len(symbol) != 0:
        print("What is this element", rand_sym, "?")
        attempt = input()
        if attempt == correct:
            print("That's correct!", attempt, "is the element of", rand_sym, ".\n")
            del symbol[rand_num] #avoid repeated symbols
        else:
            print("That's wrong, think harder!")
