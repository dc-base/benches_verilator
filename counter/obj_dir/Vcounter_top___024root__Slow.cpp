// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcounter_top.h for the primary calling header

#include "verilated.h"

#include "Vcounter_top__Syms.h"
#include "Vcounter_top___024root.h"

void Vcounter_top___024root___ctor_var_reset(Vcounter_top___024root* vlSelf);

Vcounter_top___024root::Vcounter_top___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vcounter_top___024root___ctor_var_reset(this);
}

void Vcounter_top___024root::__Vconfigure(Vcounter_top__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vcounter_top___024root::~Vcounter_top___024root() {
}
