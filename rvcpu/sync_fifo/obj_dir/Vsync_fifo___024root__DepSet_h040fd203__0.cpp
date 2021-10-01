// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsync_fifo.h for the primary calling header

#include "verilated.h"

#include "Vsync_fifo__Syms.h"
#include "Vsync_fifo___024root.h"

VL_INLINE_OPT void Vsync_fifo___024root___sequent__TOP__2(Vsync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___sequent__TOP__2\n"); );
    // Body
    if (vlSymsp->_vm_contextp__->assertOn()) {
        if (VL_LIKELY((1U & (~ ((IData)(vlSelf->empty) 
                                & (IData)(vlSelf->full)))))) {
            if (VL_UNLIKELY(vlSymsp->_vm_contextp__->assertOn())) {
                VL_WRITEF("[SVA] full and empty fail, Full: %b Empty: %b\n",
                          1,vlSelf->full,1,(IData)(vlSelf->empty));
            }
        }
    }
    VL_WRITEF("COUNT: %4d\n",8,vlSelf->sync_fifo__DOT__count);
}
