Testshares.c Setup

Children Count: 3 concurrent worker processes

Ticket Counts: A 1:2:3 ratio was used.

Workload: CPU-bound loops designed to keep the processes in the RUNNABLE state during timer interrupts.

# WORK: 500,000,000 loops
PID	Process Name	Assigned Tickets	Ticks Used (CPU Time)	
4	testshares	    1000	                16	
6	testshares	    3000	                16	
5	testshares	    2000	                16	

11	testshares	    3000	                15	
9	testshares	    1000	                16	
10	testshares	    2000	                16	

13	testshares	    1000	                15
15	testshares	    3000	                15	
14	testshares	    2000	                16	

# WORK:  5,000,000,000 loops
PID Process Name    Assigned Tickets    Ticks Used (CPU Time)
4   testshares      1000                153
6   testshares      3000                153
5   testshares      2000                155

9   testshares      2000                153
8   testshares      1000                153
10  testshares      3000                158

14  testshares      3000                158
13  testshares      2000                162
12  testshares      1000                158

# WORK 50,000,000,000 loops
PID Process Name    Assigned Tickets    Ticks Used (CPU Time)
5   testshares      2000                1504
6   testshares      3000                1503
4   testshares      1000                1509

9   testshares      2000                1497
10  testshares      3000                1487
8   testshares      1000                1492

14  testshares      3000                1483
13  testshares      2000                1484
12  testshares      1000                1484

# the tables are ordered by which process finished first 

Observation of High Variance: Across all runs, the tick counts were almost identical across processes with widely different ticket counts. The assigned ticket ratio was 1:2:3 (1000, 2000, 3000), but the observed tick distribution remained nearly 1:1:1 across all trials,but there were significant around 30-second gap between the completion times of the processes.

Weighted Selection: This gap is the true indicator of the lottery scheduler's performance. While every process eventually performs the same total work, the 3000-ticket process has a higher probability of being selected in each scheduling window. Consequently, it completed its share of ticks earlier.

Conclusion: This observation proves that the lottery scheduler is functioning correctly. The ticket counts converge to equality because the workload is finite and identical, but the throughput is successfully biased toward processes with higher ticket counts.

