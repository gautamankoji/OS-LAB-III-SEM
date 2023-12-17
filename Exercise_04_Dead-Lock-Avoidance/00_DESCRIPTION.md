# Banker's Algorithm

The **Banker's Algorithm** is a resource allocation and deadlock avoidance algorithm used in operating systems. It ensures that the system remains in a safe state by simulating the allocation of resources and performing a safety check before deciding whether further resource allocation should be allowed.

## Data Structures Used

The algorithm employs several data structures to manage information about processes and resources in the system.

### 1. Available

- It is a 1-dimensional array of size 'm,' representing the number of available resources for each resource type.
- `Available[j] = k` indicates that there are 'k' instances of resource type Rj.

### 2. Max

- It is a 2-dimensional array of size 'n * m' defining the maximum demand of each process for each resource type.
- `Max[i, j] = k` means that process Pi may request at most 'k' instances of resource type Rj.

### 3. Allocation

- It is a 2-dimensional array of size 'n * m' representing the number of resources of each type currently allocated to each process.
- `Allocation[i, j] = k` denotes that process Pi is currently allocated 'k' instances of resource type Rj.

### 4. Need

- It is a 2-dimensional array of size 'n * m' indicating the remaining resource needs of each process.
- `Need[i, j] = k` signifies that process Pi is currently allocated 'k' instances of resource type Rj.
- `Need[i, j] = Max[i, j] – Allocation[i, j]`

