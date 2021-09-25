// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsync_fifo.h"
#include "Vsync_fifo__Syms.h"

//============================================================
// Constructors

Vsync_fifo::Vsync_fifo(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vsync_fifo__Syms(_vcontextp__, _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , write{vlSymsp->TOP.write}
    , read{vlSymsp->TOP.read}
    , empty{vlSymsp->TOP.empty}
    , full{vlSymsp->TOP.full}
    , wData{vlSymsp->TOP.wData}
    , rdData{vlSymsp->TOP.rdData}
    , rootp{&(vlSymsp->TOP)}
{
}

Vsync_fifo::Vsync_fifo(const char* _vcname__)
    : Vsync_fifo(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vsync_fifo::~Vsync_fifo() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vsync_fifo___024root___eval_initial(Vsync_fifo___024root* vlSelf);
void Vsync_fifo___024root___eval_settle(Vsync_fifo___024root* vlSelf);
void Vsync_fifo___024root___eval(Vsync_fifo___024root* vlSelf);
#ifdef VL_DEBUG
void Vsync_fifo___024root___eval_debug_assertions(Vsync_fifo___024root* vlSelf);
#endif  // VL_DEBUG
void Vsync_fifo___024root___final(Vsync_fifo___024root* vlSelf);

static void _eval_initial_loop(Vsync_fifo__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vsync_fifo___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vsync_fifo___024root___eval_settle(&(vlSymsp->TOP));
        Vsync_fifo___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vsync_fifo::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsync_fifo::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsync_fifo___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vsync_fifo___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

//============================================================
// Invoke final blocks

void Vsync_fifo::final() {
    Vsync_fifo___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Utilities

VerilatedContext* Vsync_fifo::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vsync_fifo::name() const {
    return vlSymsp->name();
}
