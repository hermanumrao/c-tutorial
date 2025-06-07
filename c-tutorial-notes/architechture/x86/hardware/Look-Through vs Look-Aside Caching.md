
## Definitions

**Look-Through Policy**: Processor searches cache first → if miss, cache searches next level/memory → returns data through cache hierarchy

**Look-Aside Policy**: Processor simultaneously searches both cache and memory → requires cancel signals when found in cache


## Key Differences

|Aspect|Look-Through|Look-Aside|
|---|---|---|
|**Search Strategy**|Sequential through hierarchy|Parallel cache + memory|
|**Control Logic**|Simple, hierarchical|Complex signaling|
|**Signal Overhead**|Minimal|High (cancel signals)|
|**Usage**|Standard (95%+ hit rates)|Rarely used|
|**Bandwidth**|Efficient filtering|Wastes memory bandwidth|

## Look-Through Cache

```mermaid
sequenceDiagram
    participant CPU as Processor
    participant L1 as L1 Cache
    participant L2 as L2 Cache
    participant MEM as Memory
    
    Note over CPU,MEM: Cache Hit Scenario
    CPU->>L1: 1. Request data
    L1-->>CPU: 2. Return data (12ns)
    
    Note over CPU,MEM: L1 Miss, L2 Hit Scenario  
    CPU->>L1: 1. Request data
    L1->>L2: 2. Search L2
    L2-->>L1: 3. Return data
    L1-->>CPU: 4. Return data (117ns)
    
    Note over CPU,MEM: L1 & L2 Miss Scenario
    CPU->>L1: 1. Request data
    L1->>L2: 2. Search L2
    L2->>MEM: 3. Search Memory
    MEM-->>L2: 4. Return data
    L2-->>L1: 5. Return data
    L1-->>CPU: 6. Return data
```


## Look-Aside Cache

```mermaid
sequenceDiagram
    participant CPU as Processor
    participant CACHE as Cache
    participant MEM as Memory
    
    Note over CPU,MEM: Parallel Access
    CPU->>CACHE: 1. Search cache
    CPU->>MEM: 1. Search memory (parallel)
    
    Note over CPU,MEM: Cache Hit First
    CACHE-->>CPU: 2. Return data
    CPU->>MEM: 3. Send cancel signal
    
    Note over CPU,MEM: Memory Response First  
    MEM-->>CPU: 2. Return data
    CPU->>CACHE: 3. Handle cache response
```



## Why Look-Through Dominates

- **High Hit Rates**: Modern caches achieve 95%+ hit rates
- **Bandwidth Efficiency**: Inner caches filter requests to outer levels
- **Simpler Design**: No complex signaling required
- **Better Performance**: Avoids unnecessary memory accesses

## Application-Level Caching

For software caches, the distinction is different:

- **Look-Aside**: Application manages cache consistency and data insertion
- **Look-Through**: Cache transparently handles consistency without application involvement