// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsync_fifo.h for the primary calling header

#include "verilated.h"

#include "Vsync_fifo___024root.h"

extern const VlUnpacked<CData/*0:0*/, 2048> Vsync_fifo__ConstPool__TABLE_h38df7e80_0;
extern const VlUnpacked<CData/*7:0*/, 2048> Vsync_fifo__ConstPool__TABLE_h195332e7_0;

VL_INLINE_OPT void Vsync_fifo___024root___sequent__TOP__3(Vsync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___sequent__TOP__3\n"); );
    // Init
    SData/*10:0*/ __Vtableidx1;
    CData/*2:0*/ __Vdlyvdim0__sync_fifo__DOT__mem__v0;
    IData/*31:0*/ __Vdlyvval__sync_fifo__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__sync_fifo__DOT__mem__v0;
    // Body
    __Vdlyvset__sync_fifo__DOT__mem__v0 = 0U;
    if (vlSelf->rst) {
        if (((IData)(vlSelf->read) & (~ (IData)(vlSelf->empty)))) {
            vlSelf->rdData = vlSelf->sync_fifo__DOT__mem
                [vlSelf->sync_fifo__DOT__r_ptr];
            vlSelf->sync_fifo__DOT__r_ptr = ((7U == (IData)(vlSelf->sync_fifo__DOT__r_ptr))
                                              ? 0U : 
                                             (7U & 
                                              ((IData)(1U) 
                                               + (IData)(vlSelf->sync_fifo__DOT__r_ptr))));
        }
        if (((IData)(vlSelf->write) & (~ (IData)(vlSelf->full)))) {
            __Vdlyvval__sync_fifo__DOT__mem__v0 = vlSelf->wData;
            __Vdlyvset__sync_fifo__DOT__mem__v0 = 1U;
            __Vdlyvdim0__sync_fifo__DOT__mem__v0 = vlSelf->sync_fifo__DOT__w_ptr;
            vlSelf->sync_fifo__DOT__w_ptr = (((7U == (IData)(vlSelf->sync_fifo__DOT__w_ptr)) 
                                              & (~ (IData)(vlSelf->full)))
                                              ? 0U : 
                                             (7U & 
                                              ((IData)(1U) 
                                               + (IData)(vlSelf->sync_fifo__DOT__w_ptr))));
        }
    } else {
        vlSelf->sync_fifo__DOT__r_ptr = 0U;
        vlSelf->sync_fifo__DOT__w_ptr = 0U;
    }
    __Vtableidx1 = (((IData)(vlSelf->sync_fifo__DOT__count) 
                     << 3U) | (((IData)(vlSelf->write) 
                                << 2U) | (((IData)(vlSelf->read) 
                                           << 1U) | (IData)(vlSelf->rst))));
    if (Vsync_fifo__ConstPool__TABLE_h38df7e80_0[__Vtableidx1]) {
        vlSelf->sync_fifo__DOT__count = Vsync_fifo__ConstPool__TABLE_h195332e7_0
            [__Vtableidx1];
    }
    if (__Vdlyvset__sync_fifo__DOT__mem__v0) {
        vlSelf->sync_fifo__DOT__mem[__Vdlyvdim0__sync_fifo__DOT__mem__v0] 
            = __Vdlyvval__sync_fifo__DOT__mem__v0;
    }
    vlSelf->full = (8U == VL_EXTENDS_II(32,8, (IData)(vlSelf->sync_fifo__DOT__count)));
    vlSelf->empty = (0U == VL_EXTENDS_II(32,8, (IData)(vlSelf->sync_fifo__DOT__count)));
}

void Vsync_fifo___024root___sequent__TOP__2(Vsync_fifo___024root* vlSelf);

void Vsync_fifo___024root___eval(Vsync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vsync_fifo___024root___sequent__TOP__2(vlSelf);
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlSelf->rst)) & (IData)(vlSelf->__Vclklast__TOP__rst)))) {
        Vsync_fifo___024root___sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vsync_fifo___024root___eval_debug_assertions(Vsync_fifo___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->write & 0xfeU))) {
        Verilated::overWidthError("write");}
    if (VL_UNLIKELY((vlSelf->read & 0xfeU))) {
        Verilated::overWidthError("read");}
}
#endif  // VL_DEBUG
