// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcounter_top.h"
#include "Vcounter_top__Syms.h"

//============================================================
// Constructors

Vcounter_top::Vcounter_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vcounter_top__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , count{vlSymsp->TOP.count}
    , rootp{&(vlSymsp->TOP)}
{
}

Vcounter_top::Vcounter_top(const char* _vcname__)
    : Vcounter_top(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vcounter_top::~Vcounter_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vcounter_top___024root___eval_initial(Vcounter_top___024root* vlSelf);
void Vcounter_top___024root___eval_settle(Vcounter_top___024root* vlSelf);
void Vcounter_top___024root___eval(Vcounter_top___024root* vlSelf);
#ifdef VL_DEBUG
void Vcounter_top___024root___eval_debug_assertions(Vcounter_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vcounter_top___024root___final(Vcounter_top___024root* vlSelf);

static void _eval_initial_loop(Vcounter_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vcounter_top___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vcounter_top___024root___eval_settle(&(vlSymsp->TOP));
        Vcounter_top___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vcounter_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcounter_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcounter_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vcounter_top___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

//============================================================
// Invoke final blocks

void Vcounter_top::final() {
    Vcounter_top___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vcounter_top::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vcounter_top::name() const {
    return vlSymsp->name();
}
