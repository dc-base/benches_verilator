// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtopm.h for the primary calling header

#include "verilated.h"

#include "Vtopm__Syms.h"
#include "Vtopm___024root.h"

void Vtopm___024root___ctor_var_reset(Vtopm___024root* vlSelf);

Vtopm___024root::Vtopm___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vtopm___024root___ctor_var_reset(this);
}

void Vtopm___024root::__Vconfigure(Vtopm__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vtopm___024root::~Vtopm___024root() {
}
