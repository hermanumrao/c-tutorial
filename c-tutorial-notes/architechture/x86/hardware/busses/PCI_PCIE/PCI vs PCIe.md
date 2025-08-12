Here's a comparison of PCI and PCIe in a table format:

| **Feature**        | **PCI (Peripheral Component Interconnect)**   | **PCIe (PCI Express)**                             |
| ------------------ | --------------------------------------------- | -------------------------------------------------- |
| **Architecture**   | Shared parallel bus (all devices share lines) | Point-to-point serial (separate links per device)  |
| **Throughput**     | Lower maximum system bus throughput           | Significantly higher maximum system bus throughput |
| **I/O Pin Count**  | Higher                                        | Lower                                              |
| **Physical Size**  | Larger footprint                              | Smaller footprint                                  |
| **Performance**    | Limited performance scaling for bus devices   | Better performance scaling for bus devices         |
| **Error Handling** | Basic error detection and reporting           | More detailed (Advanced Error Reporting - AER)     |
| **Hot-Swap**       | Generally not supported natively              | Native hot-swap functionality                      |


But PCI has some shortcomings. As [processors](https://computer.howstuffworks.com/microprocessor.htm), [video cards](https://computer.howstuffworks.com/graphics-card.htm), sound cards and networks have gotten faster and more powerful, PCI has stayed the same. It has a fixed width of 32 [bits](https://computer.howstuffworks.com/bytes.htm#pt2) and can handle only 5 devices at a time. The newer, 64-bit PCI-X bus provides more bandwidth, but its greater width compounds some of PCI's other issues.

Conceptually, the PCI Express bus is a high-speed serial replacement of the older PCI/PCI-X bus. One of the key differences between the PCI Express bus and the older PCI is the bus topology; PCI uses a shared parallel bus architecture, in which the PCI host and all devices share a common set of address, data, and control lines. In contrast, PCI Express is based on point-to-point topology, with separate serial links connecting every device to the root complex (host). Because of its shared bus topology, access to the older PCI bus is arbitrated (in the case of multiple masters), and limited to one master at a time, in a single direction. Furthermore, the older PCI clocking scheme limits the bus clock to the slowest peripheral on the bus (regardless of the devices involved in the bus transaction). In contrast, a PCI Express bus link supports full-duplex communication between any two endpoints, with no inherent limitation on concurrent access across multiple endpoints.
