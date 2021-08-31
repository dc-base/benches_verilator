// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtopm.h"
#include "Vtopm__Syms.h"

//============================================================
// Constructors

Vtopm::Vtopm(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vtopm__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rootp{&(vlSymsp->TOP)}
{
}

Vtopm::Vtopm(const char* _vcname__)
    : Vtopm(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vtopm::~Vtopm() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vtopm___024root___eval_initial(Vtopm___024root* vlSelf);
void Vtopm___024root___eval_settle(Vtopm___024root* vlSelf);
void Vtopm___024root___eval(Vtopm___024root* vlSelf);
#ifdef VL_DEBUG
void Vtopm___024root___eval_debug_assertions(Vtopm___024root* vlSelf);
#endif  // VL_DEBUG
void Vtopm___024root___final(Vtopm___024root* vlSelf);

static void _eval_initial_loop(Vtopm__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vtopm___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vtopm___024root___eval_settle(&(vlSymsp->TOP));
        Vtopm___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vtopm::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtopm::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtopm___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vtopm___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

//============================================================
// Invoke final blocks

void Vtopm::final() {
    Vtopm___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vtopm::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vtopm::name() const {
    return vlSymsp->name();
}
