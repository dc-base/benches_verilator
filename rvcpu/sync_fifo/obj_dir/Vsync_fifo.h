// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VSYNC_FIFO_H_
#define VERILATED_VSYNC_FIFO_H_  // guard

#include "verilated.h"

class Vsync_fifo__Syms;
class Vsync_fifo___024root;
class VerilatedVcdC;

// This class is the main interface to the Verilated model
class Vsync_fifo VL_NOT_FINAL {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vsync_fifo__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&rst,0,0);
    VL_IN8(&write,0,0);
    VL_IN8(&read,0,0);
    VL_OUT8(&empty,0,0);
    VL_OUT8(&full,0,0);
    VL_IN(&wData,31,0);
    VL_OUT(&rdData,31,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vsync_fifo___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vsync_fifo(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vsync_fifo(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vsync_fifo();
  private:
    VL_UNCOPYABLE(Vsync_fifo);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp() const;
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
