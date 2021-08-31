// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vcounter_top__Syms.h"
#include "Vcounter_top.h"
#include "Vcounter_top___024root.h"

// FUNCTIONS
Vcounter_top__Syms::~Vcounter_top__Syms()
{
}

Vcounter_top__Syms::Vcounter_top__Syms(VerilatedContext* contextp, const char* namep,Vcounter_top* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP(namep)
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(this, true);
}
