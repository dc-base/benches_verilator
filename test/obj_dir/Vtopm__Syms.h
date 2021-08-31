// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOPM__SYMS_H_
#define VERILATED_VTOPM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtopm.h"

// INCLUDE MODULE CLASSES
#include "Vtopm___024root.h"

// SYMS CLASS (contains all model state)
class Vtopm__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtopm* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtopm___024root                TOP;

    // CONSTRUCTORS
    Vtopm__Syms(VerilatedContext* contextp, const char* namep, Vtopm* modelp);
    ~Vtopm__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
