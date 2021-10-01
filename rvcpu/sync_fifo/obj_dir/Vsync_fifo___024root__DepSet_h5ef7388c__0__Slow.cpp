// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsync_fifo.h for the primary calling header

#include "verilated.h"

#include "Vsync_fifo___024root.h"

VL_ATTR_COLD void Vsync_fifo___024root___initial__TOP__1(Vsync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___initial__TOP__1\n"); );
    // Body
    VL_WRITEF("hello from binded assertion module\n");
}

VL_ATTR_COLD void Vsync_fifo___024root___settle__TOP__4(Vsync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___settle__TOP__4\n"); );
    // Body
    vlSelf->full = (8U == VL_EXTENDS_II(32,8, (IData)(vlSelf->sync_fifo__DOT__count)));
    vlSelf->empty = (0U == VL_EXTENDS_II(32,8, (IData)(vlSelf->sync_fifo__DOT__count)));
}

VL_ATTR_COLD void Vsync_fifo___024root___eval_initial(Vsync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___eval_initial\n"); );
    // Body
    Vsync_fifo___024root___initial__TOP__1(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vsync_fifo___024root___eval_settle(Vsync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___eval_settle\n"); );
    // Body
    Vsync_fifo___024root___settle__TOP__4(vlSelf);
}

VL_ATTR_COLD void Vsync_fifo___024root___final(Vsync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___final\n"); );
}

VL_ATTR_COLD void Vsync_fifo___024root___ctor_var_reset(Vsync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->write = VL_RAND_RESET_I(1);
    vlSelf->read = VL_RAND_RESET_I(1);
    vlSelf->wData = VL_RAND_RESET_I(32);
    vlSelf->rdData = VL_RAND_RESET_I(32);
    vlSelf->empty = VL_RAND_RESET_I(1);
    vlSelf->full = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->sync_fifo__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->sync_fifo__DOT__w_ptr = VL_RAND_RESET_I(3);
    vlSelf->sync_fifo__DOT__r_ptr = VL_RAND_RESET_I(3);
    vlSelf->sync_fifo__DOT__count = 0;
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
