The **Portable Operating System Interface** (**POSIX**)
is a family of standards especially specified by IEEE which defines software compatibility in accordance with variants for unix.
It basically defines the bare-minimum required API-functionalities, along with command-line shells and utility interfaces for software compatibility with unix systems.

## Basic posix compliances
Before 1997, POSIX comprised several standards:

- ### **POSIX.1**: 
  Core Services (incorporates Standard [ANSI C](https://en.wikipedia.org/wiki/ANSI_C "ANSI C")) (IEEE Std 1003.1-1988)
    - Process Creation and Control
    - Signals "Signal (IPC)"
        - Floating Point Exceptions
        - Segmentation / Memory Violations
        - Illegal Instructions
        - Bus Errors
        - Timers
    - File and Directory Operations
    - Pipes
    - C Library (Standard C)
    - The POSIX terminal interface
- ### **POSIX.1b**: 
  Real-time extensions (IEEE Std 1003.1b-1993, later appearing as librt—the Realtime Extensions library)
    - Priority Scheduling
    - Real-Time Signals    
    - Clocks and Timers
    - Semaphores
    - Message Passing
    - Shared Memory
    - Asynchronous and Synchronous I/O
    - Memory Locking Interface
- ### **POSIX.1c**: 
  Threads extensions
    - Thread Creation, Control, and Cleanup
    - Thread Scheduling
    - Thread Synchronization
    - Signal Handling
- ### **POSIX.2**:
  Shell and Utilities (IEEE Std 1003.2-1992)
    - Command Interpreter
    - Utility Programs

#### Reference Link:
[https://pubs.opengroup.org/onlinepubs/9699919799/](https://pubs.opengroup.org/onlinepubs/9699919799/)