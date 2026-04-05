#  UNIT-1 WORKSHEET 1 - ANSWERS

## Multiple Choice Questions
1. **C** - The kernel is the core component that manages hardware resources and provides essential services.
2. **D** - All of the above
3. **C** - Application development
4. **B** - A way for programs to request services from the operating system
5. **B** - Kernel
6. **B** - Loads the kernel into memory
7. **B** - Creates a new process by duplicating the calling process
8. **C** - Process ID (PID) of the child process
9. **D** - Microkernels emphasize minimalism, with essential services implemented as user-level processes
10. **B** - To execute multiple programs concurrently for better CPU utilization

## Subjective Questions
1. Real-time OS are designed for systems where tasks must finish by a specific deadline (like airplane controls or medical devices). General-purpose OS like Windows focus on running many different programs smoothly for different users. Real-time systems rarely multitask and use simple scheduling to ensure critical tasks complete on time. Regular operating systems allow multitasking and switching between programs, managing many processes fairly. Real-time systems are simpler but limited; general-purpose systems are more flexible but complex.

2. Monolithic kernels put all operating system functions (handling files, memory, processes) in one place, making them fast but hard to maintain if there's a problem. Microkernel design breaks functions into separate pieces that work independently, making it easier to fix issues but slower. Linux uses a monolithic approach (fast), while MINIX uses a microkernel approach (safer but slower). Most modern systems use monolithic because they're simpler and faster, even though microkernel systems are more organized and reliable.

3. When you turn on your computer, a special startup program stored in ROM runs first. This program loads the operating system kernel from the hard disk into memory. The kernel then sets up the computer's hardware, manages memory, and starts the first program. That first program then launches other system services and login screens for users. This whole process takes a few seconds and sets everything up so you can use the computer.

4. Device drivers are software that translate instructions from programs into commands that hardware like printers and monitors understand. They act as a bridge between your applications and physical devices. Without drivers, your computer wouldn't know how to talk to new hardware. Drivers handle specific details of each device, so the operating system doesn't need to understand every printer or graphics card model. When you install new hardware, you usually need to install its driver too.

5. System calls are ways for programs to ask the operating system to do important tasks like reading files, creating new programs, or using memory. They work like a controlled door between user programs and the kernel. Programs can't directly access hardware; they must use system calls to request the OS to do it. This protects the system because the OS can check permissions and prevent one program from damaging another. Examples include opening files, creating processes, and printing text.

6. Interrupts are signals that pause what the computer is currently doing to handle something urgent. For example, when you click the mouse, an interrupt tells the computer to stop and process your click. Without interrupts, the computer would constantly check devices like printers and keyboards, wasting time. Interrupts let devices notify the computer immediately when they need attention. The OS has special code called handlers that respond to different types of interrupts quickly and then resume normal work.

---

# WORKSHEET 2 - ANSWERS

## Multiple Choice Questions
1. **A** - A program in execution
2. **C** - To store information about a process
3. **C** - Determining the order in which processes are executed by the CPU
4. **B** - Shortest Job Next (SJN)
5. **B** - A lightweight process sharing the same address space
6. **B** - The amount of time a process is allowed to run in one continuous time slot
7. **C** - Kernel-level threads are visible to the OS scheduler, allowing better multiprocessor utilization
8. **B** - Lower context-switching overhead
9. **A** - All threads in the process are blocked
10. **A** - 4 units of time (P1: 0-6, P2 waits 2-6 = 4 units)

## Subjective Questions
1. A process is a running program with its own private memory space. Each process has a unique ID (PID) and contains code, data, and a stack for variables. The OS tracks each process using a Process Control Block (PCB) that stores information like where it is, what memory it uses, and what files it has open. Processes run independently and can't directly access each other's memory, which keeps them safe. The OS scheduler decides which process runs next and how long each gets the CPU.

2. A process goes through different states: New (created), Ready (waiting for CPU), Running (using CPU), Blocked (waiting for something like disk read), and Terminated (finished). When a process needs to read a file, it moves to Blocked state until the file loads. The scheduler constantly checks which processes are ready and picks which one gets the CPU next. Process states change based on events like finishing time, finishing I/O, or the scheduler giving another process a turn. This cycling keeps the system responsive and fair.

3. Preemptive scheduling interrupts programs and switches to another one after a short time (like 10ms), useful for responsive systems where many programs need attention. Round Robin is a preemptive method giving each program equal CPU time. Non-preemptive scheduling lets one program run until it finishes naturally, then switches to the next. FCFS (First-Come-First-Serve) is non-preemptive. Preemptive is better for computers with many users; non-preemptive is simpler but one slow program blocks others.

4. A thread is like a lightweight process inside a program that shares memory with other threads but runs independently. If a process is like a factory, threads are like workers in that factory who share tools and workspace. Multiple threads in one process run simultaneously and can share data easily. Threads are cheaper to create and switch between than separate processes. They're useful when you want to do multiple things in one program, like reading a file while updating a display.

5. User-level threads are managed by the program itself, not the OS, so they're fast and simple but if one thread waits for a file, the whole program waits. Kernel-level threads are managed by the OS, so the OS can let one thread wait while others keep running. Modern systems with multiple CPU cores use kernel-level threads to truly run code in parallel. User-level threads are useful for older systems or when you want simple, fast threading without OS help.

6. **Turnaround time for P2 = 18 ms**. With Round Robin and 4ms time slices: P1 runs 0-4ms, P2 runs 4-8ms (arrives at 2, so waits 2ms), P3 runs 8-12ms, P1 finishes 12-16ms, P2 finishes 16-20ms. P2 started at 16ms and arrived at 2ms, so turnaround = 20-2 = 18ms. Round Robin gives each process a fair turn on the CPU, so everyone gets served but total time might be longer than if we ran programs by priority.

---

# WORKSHEET 3 - ANSWERS

## Multiple Choice Questions
1. **C** - Coordinating the execution of multiple processes
2. **C** - Undesirable interference between concurrent operations
3. **B** - Managing access to shared resources
4. **A** - Mutual exclusion
5. **B** - Inability to acquire necessary resources and proceed
6. **C** - Producer-Consumer Problem
7. **B** - Ensure mutual exclusion among processes
8. **A** - The maximum number of resources that each process may request
9. **C** - Both the maximum need and available resources
10. **A** - Ready→Running→Blocked→Ready→Running→Terminated

## Subjective Questions
1. Synchronization ensures that when multiple programs access the same data, they don't interfere with each other. Without it, imagine two programs withdrawing money from the same account at the same time—both could withdraw successfully and the bank loses money. Locks and semaphores are tools that ensure only one program accesses data at a time. Synchronization prevents data corruption and crashes but slows things down because programs must wait. It's essential but comes with challenges like deadlocks where programs wait forever.

2. The critical section problem is a code section where shared data is accessed—only one process should be there at a time. Three things are needed: first, mutual exclusion (only one process at a time), second, progress (waiting processes should get a turn), and third, bounded waiting (no process waits forever). Think of it like a bathroom—if two people enter together, chaos! Solutions use locks to ensure only one person enters. This is important because most programs share files and data that must be protected.

3. Deadlock happens when processes are stuck waiting for resources each other has. For example, Process A has Resource 1 and waits for Resource 2, while Process B has Resource 2 and waits for Resource 1—nobody moves! Four conditions must all be true for deadlock: mutual exclusion (resources are taken by one), hold-and-wait (holding one while wanting another), no preemption (can't force release), and circular wait (circular dependency). If any condition is missing, deadlock won't happen.

4. Deadlock prevention stops it by breaking one of the four conditions. For example, require all resources upfront so no hold-and-wait, or order resources so no circular waits. Prevention is simple but wastes resources. Deadlock avoidance checks before giving resources if it's safe, like Banker's algorithm for money lending. If granting a resource might cause deadlock, refuse it. Avoidance is better for resource use but more complex. Prevention is forcing the issue; avoidance is careful checking before allowing something.

5. **Average wait time = 5.33 ms; Average turnaround = 11.33 ms**. Priority scheduling runs highest priority first: P2 (priority 1) runs 0-4ms, P3 (priority 2) runs 4-12ms, P1 (priority 3) runs 12-18ms. P2 doesn't wait (0ms), P3 doesn't wait (0ms), P1 waits 12ms. Average wait = (0+0+12)/3 = 4ms. Turnaround (completion time - arrival time): P2=4ms, P3=12ms, P1=6ms, average=7.33ms. Higher priorities get served first, so they wait less.

6. System is **NOT in safe state**. Looking at available resources [2,1,3]: no process can finish and give back resources. P1 needs [2,2,1] but we have [2,1,3], P5 needs [3,4,1], P4 needs [3,2,5]—none fit. Since no process can complete, none can release resources for others to finish. This violates safety rules and might cause deadlock. A safe state means at least one process can complete and return resources to help others. This system is stuck and unsafe.

---

# WORKSHEET 4 - ANSWERS

## Multiple Choice Questions
1. **B** - RAM
2. **B** - To translate virtual addresses to physical addresses
3. **C** - ext4
4. **D** - No moving parts
5. **A** - FCFS (First-Come-First-Serve)
6. **A** - Excessive page faults leading to degraded performance
7. **B** - Shortest Seek Time First (SSTF)
8. **A** - Reduced page faults
9. **C** - Increased Data Redundancy and Fault Tolerance
10. **A** - 20 bits for page number, 12 bits for offset (2^12 = 4096 bytes/page needs 12 bits, remainder for page number)

## Subjective Questions
1. LRU (Least Recently Used) removes the page you haven't used for the longest time when memory is full. It works well because programs usually use the same data repeatedly (temporal locality). Advantages: fast for programs following patterns, works well for loops and sequential reading. Disadvantages: tracking which pages are used takes time and memory overhead. It fails poorly if your program accesses data patterns that don't repeat, causing lots of page faults. Real systems use simpler approximations like the clock algorithm that give similar results with less overhead.

2. A disk has concentric rings called tracks going around, and each track is split into pieces called sectors (like pizza slices). A cylinder is the same track on multiple disk layers. Tracks are numbered from outside to inside, sectors hold your data (usually 512 bytes or more). To read data, the disk head must move to the right track and wait for the sector to spin under it. Logical Block Addressing (LBA) lets the OS ignore these physical details and just ask for block numbers. Understanding disk structure helps us read data faster by minimizing head movement.

3. Disk partitioning splits one disk into multiple independent sections. Each partition can have different operating systems, file systems, or data types. Benefits include organizing data (OS separate from documents), supporting multiple OS boots from one disk, and containing damage if one partition corrupts. Security is improved because user data can be restricted separately from system files. Performance improves because fragmentation is reduced per partition. You can also backup and maintain each partition independently, making disk management easier.

4. **Total page faults = 8**. Reference sequence [1,2,3,4,1,2,5,1,2,3,4,5] with 3 frames available. Faults happen when: 1 (frame empty), 2 (empty), 3 (empty), 4 (need to remove oldest—that's 1), 5 (remove 2), 3 (remove 4), 4 (remove 2), then 5 hits (already there). Counting: 8 faults and 4 hits. LRU removes the page you haven't used recently when space is needed, keeping popular pages in memory. This method works well for this sequence.

5. RAID0 splits data across multiple drives for speed but no backup—if one drive fails, all data is lost. RAID1 copies data to two drives (mirroring), so if one fails you still have a copy, but you only get 50% storage space. RAID5 uses three or more drives, splitting data cleverly with parity (math backup info), so losing one drive doesn't lose data. RAID5 uses about 67% of total space and survives one drive failure. RAID5 is most popular because it balances cost, storage space, and safety.

6. **Total head movement = 120 tracks** using SSTF. Starting at track 50, requests at [45,60,20,90,10]. SSTF picks the closest request each time: 50→45 (distance 5), 45→20 (distance 25), 20→10 (distance 10), 10→90 (distance 80). Total = 5+25+10+80 = 120 tracks. SSTF always serves the nearest request next, which sounds smart but can cause long jumps at the end. It minimizes movement at each step but may not be globally fastest compared to other scheduling methods.

# UNIT-2
# WORKSHEET 1 (DBMS) - ANSWERS

## Multiple Choice Questions
1. **B** - Double outlined Rectangle (weak entity)
2. **D** - None
3. **A** - Cardinality is the number of tuples (rows)
4. **A** - 1-c, 2-a, 3-b
5. **D** - II and IV
6. **D** - PQR may be a candidate key
7. **A** - CD is not a key
8. **D** - All of the above
9. **A** - AB
10. **B** - 3 (assuming common ER mapping of 2 entity tables + 1 relationship table)

## Subjective Questions
1. **Three commands each:** DDL commands are used to define database structure, like creating or changing tables. Good examples are `CREATE`, `ALTER`, and `DROP`. DML commands are used to work with data inside tables. Common examples are `INSERT`, `UPDATE`, and `DELETE` (some books also include `SELECT` separately as DQL). DCL commands control permissions and access of users in the database. Common examples are `GRANT`, `REVOKE`, and `DENY` (DBMS-dependent). In simple terms: DDL builds structure, DML changes records, and DCL secures who can do what in the database.

2. The query is: `SELECT * FROM Student WHERE gender='F' AND marks>65;`. Female rows are roll 2 (Aliya, 70), roll 3 (Aliya, 80), and roll 5 (Swati, 65). Condition needs **both** female and marks strictly greater than 65. So roll 2 and roll 3 satisfy it, but roll 5 does not because 65 is not greater than 65. Therefore, total returned rows = **2**. This question checks logical filtering with `AND`, where both conditions must be true. If the condition had been `marks>=65`, then roll 5 would also be included and answer would become 3.

3. Since the ER diagram image is not visible in text, exact table count depends on relationship type (1:1, 1:N, or M:N). A common minimum mapping is: one table each for entities M, N, and P, plus separate tables for relationships R1 and R2 if they are many-to-many or have their own attributes. In that common case, total tables = **5**. Typical structure: `M(M_id, ...)`, `N(N_id, ...)`, `P(P_id, ...)`, `R1(M_id, N_id, ... )`, `R2(N_id, P_id, ... )` with composite primary keys in relationship tables. If relationships are 1:N with no attributes, fewer tables may be possible.

4. (i) We should **not** take `QTY` as primary key because primary key values must be unique and non-null. In given SALE table, `QTY` has duplicate value 10 (for PRODID 1 and 3), so it violates uniqueness. Also quantity can change over time, so it is not a stable identifier. (ii) Best suitable primary key is `PRODID`, because product ID is unique for each row (1,2,3,4) and naturally identifies one product record. A good key should be unique, stable, and minimal. `PRODID` matches these properties much better than transaction-like columns such as quantity or amount.

5. The SQL checks students who have registered for **all courses of D01**. In `Course`, D01 has courses `C11` and `C12`. Now check each student in `Register`: S01 has both C11 and C12 (qualifies), S02 has only C11 (not), S03 has C21,C22,C23 (not), S04 has both C11 and C12 (qualifies), S05 has C11 and C21 (not). So qualifying students are **S01 and S04**, which means number of rows returned is **2**. This is a classic “for all” query using `NOT EXISTS (A EXCEPT B)` pattern, where missing even one required course removes that student from result.

6. Cartesian product combines every row of T1 with every row of T2. Cardinality multiplies: `10 × 20 = 200` rows. Degree (number of columns) adds: `4 + 3 = 7` columns. So result has **degree = 7** and **cardinality = 200**. Conceptually, each row of T1 pairs with all rows of T2, so if T1 has 10 rows and each gets matched with 20 rows of T2, total 200 tuples are formed. This operation is also called cross join and is useful as an intermediate step, though in practice we usually add join conditions to avoid very large results.

---

# WORKSHEET 2 (DBMS) - ANSWERS

## Multiple Choice Questions
1. **A** - 4
2. **A** - 1NF
3. **B** - 2NF
4. **B** - AC
5. **A** - $2^d - 1$
6. **A** - (2,3,3,5)
7. **A** - `{t.FNAME,t.LNAME | EMPLOYEE(t) AND t.SALARY>20000}`
8. **C** - S1 correct, S2 incorrect
9. **C** - 800
10. **D** - COUNT(*)

## Subjective Questions
1. ACID properties make database transactions safe and reliable. **A (Atomicity)** means all steps of a transaction happen completely or none happen at all. **C (Consistency)** means data always follows defined rules before and after transaction. **I (Isolation)** means parallel transactions should not disturb each other’s intermediate work. **D (Durability)** means once a transaction is committed, data remains saved even after crash or restart. For example, in money transfer, amount should be deducted and added together atomically. ACID prevents partial updates, invalid states, and data corruption, especially in multi-user systems where many operations happen at the same time.

2. An alternate key is a candidate key that is **not selected** as the primary key. In a table, there can be multiple candidate keys (all uniquely identify rows). We choose one as primary key, and remaining candidate keys become alternate keys. Example: In a student table, both `roll_no` and `email` may uniquely identify students. If `roll_no` is chosen as primary key, then `email` becomes an alternate key. Alternate keys still enforce uniqueness and are very important in real systems, because they provide backup unique identifiers and help avoid duplicate records from other business fields.

3. (a) Primary keys: In `EMP`, best primary key is `EMPNO` because each employee number is unique. In `JOB`, best primary key is `DEPTNO` because each department appears once. (b) Foreign key in EMP is `DEPTNO`, referencing `JOB(DEPTNO)`. (c) We should **not** delete PETER’s JOB row blindly. (d) Reason: EMP table has employee records (like E001 and E003) with `DEPTNO=10`, so deleting that parent department row would break referential integrity unless cascade rule is defined. Safe approach is either update/move dependent employees first or use `ON DELETE CASCADE` if business policy allows automatic child deletion.

4. SQL query:
`SELECT name FROM employees WHERE salary > 30000;`
This query filters rows from the `employees` table and returns only the `name` column for employees earning more than 30000. It uses a simple `WHERE` condition with a comparison operator. If you want full employee details instead of only names, replace `name` with `*`. If salary can contain nulls, they are automatically excluded from `> 30000` comparison. This type of query is common in payroll reports and HR filtering. You can also sort result by salary using `ORDER BY salary DESC` to see highest paid names first.

5. A foreign key is a column (or set of columns) in one table that references the primary key of another table. It creates a link between tables and enforces referential integrity, meaning child rows cannot point to non-existing parent rows. For example, `orders.customer_id` referencing `customers.id`. A table can have **multiple foreign keys**; there is no fixed small number like one or two. Practical limit depends on DBMS and design quality. Multiple foreign keys are common in junction tables. Good foreign key usage reduces orphan records and keeps data relationships correct when inserting, updating, or deleting data.

6. Mr. Peter should use the `ALTER TABLE` command with `ADD COLUMN`. Example:
`ALTER TABLE table_name ADD COLUMN new_column_name data_type;`
This command modifies an existing table structure without deleting old data. It is the standard way to add missing columns later in MySQL and other SQL systems. For example, if he wants to add `email VARCHAR(100)` to `students`, he can run `ALTER TABLE students ADD COLUMN email VARCHAR(100);`. He can also set defaults or constraints while adding the column. This is safer and better than dropping and recreating table, because existing rows stay preserved.

7. SQL query:
`DELETE FROM customers WHERE age < 18;`
This removes all rows from `customers` where age is below 18. It is a DML operation and affects only matching records. Before running delete in real systems, we should verify using `SELECT * FROM customers WHERE age < 18;` so we know exactly what will be removed. If the database is transactional, it is safer to run inside a transaction so we can rollback if needed. Also check foreign key dependencies; deleting parent rows may fail or cascade depending on constraint rules. Always take backup in production before bulk deletion.

---

# WORKSHEET 3 (DBMS) - ANSWERS

## Multiple Choice Questions
1. **B** - C *(based on common interpretation of underlined primary keys in the given text)*
2. **A** - i, ii, iv only
3. **A** - i and iii only
4. **A** - i and ii only
5. **A** - i, ii, and iii only
6. **C** - It removes duplicate rows from the result set
7. **A** - Only S1
8. **D** - 31
9. **A** - Only (i) *(intended SQL uses `BETWEEN`; query text has a typo)*
10. **A** - 3.33

## Subjective Questions
1. In the visitor table, likely candidate keys are `VisitorID` and `ContactNumber`, because both appear unique for each row. `VisitorName` is not a good key because names can repeat in real life. The best primary key should be `VisitorID` because it is short, stable, and system-generated. Phone numbers may change, so they are better as alternate keys. Degree of table means number of columns, so degree = **3** (`VisitorID`, `VisitorName`, `ContactNumber`). Cardinality means number of rows, so cardinality = **4** (V001 to V004). This is a good example of choosing a stable identifier over user-entered fields.

2. SQL solution:
`SELECT product_id FROM Products WHERE low_fats = 'Y' AND recyclable = 'Y';`
This query returns IDs of products that satisfy both conditions together: low fat and recyclable. The `AND` operator ensures only rows with both `Y` values are selected. Since `product_id` is primary key, each returned value is unique already. Order is not required by problem, so no `ORDER BY` is needed. This is a straightforward filter query and very common in coding interviews to test basic `SELECT` with conditions. If required, we can format output by aliasing column or sorting by `product_id`.

3. SQL solution:
`SELECT name FROM Customer WHERE referee_id <> 2 OR referee_id IS NULL;`
This returns customer names who were not referred by customer id 2. The `OR referee_id IS NULL` part is important because null means no referee assigned; such rows should be included. If we use only `referee_id <> 2`, null rows may get skipped because null comparisons are unknown in SQL logic. This question checks understanding of null handling and conditional filtering. The result can be returned in any order, as requested. This pattern is frequently used in practical filtering where missing values are valid data.

4. SQL solution:
`SELECT v.customer_id, COUNT(*) AS count_no_trans`
`FROM Visits v LEFT JOIN Transactions t ON v.visit_id = t.visit_id`
`WHERE t.transaction_id IS NULL`
`GROUP BY v.customer_id;`
This query first keeps all visits using left join, then filters only those visits where no matching transaction exists (`t.transaction_id IS NULL`). After that, it groups by customer and counts such visits. Result gives each user id and how many times they visited without purchasing. This is a classic anti-join use case in SQL. It is common in analytics for finding drop-offs, inactive purchase behavior, or conversion funnel gaps.

5. SQL solution:
`SELECT * FROM Cinema`
`WHERE id % 2 = 1 AND description <> 'boring'`
`ORDER BY rating DESC;`
This returns movies with odd IDs and non-boring descriptions, then sorts from highest rating to lowest. `id % 2 = 1` ensures odd-numbered IDs only. `description <> 'boring'` removes boring rows exactly as required. Ordering by `rating DESC` gives top-rated matching movies first. Since id is primary key, each result row is unique naturally. This problem tests filtering by multiple conditions and sorting output. Very standard interview pattern combining `WHERE` and `ORDER BY`.

6. SQL solution:
`SELECT teacher_id, COUNT(DISTINCT subject_id) AS cnt`
`FROM Teacher`
`GROUP BY teacher_id;`
We count distinct subjects for each teacher because a teacher can teach the same subject in different departments, and question asks unique subjects only. `GROUP BY teacher_id` makes one output row per teacher. `COUNT(DISTINCT subject_id)` avoids duplicate subject counting for same teacher. This query is simple but important because many students forget `DISTINCT` and overcount. Result order is not specified, so any order is acceptable. This is a common aggregation question on grouping and unique counting in SQL.

---

# WORKSHEET 4 (DBMS) - ANSWERS

## Multiple Choice Questions
1. **D** - `SELECT Pname FROM Project WHERE dnum=4;`
2. **A** - Composite primary key `(id, lastname)`
3. **C** - `SELECT class_name, AVG(age) FROM class GROUP BY class_name HAVING AVG(age)>10;`
4. **A** - `SELECT Branch, SUM(Salary) FROM Employee GROUP BY Branch;`
5. **B** - Size of block and size of address
6. **C** - Exclusive
7. **C** - 80
8. **D** - Neither view serializable nor conflict serializable
9. **D** - All I, II, III, IV, and V
10. **A** - Only I

## Subjective Questions
1. SQL query:
`SELECT * FROM employees ORDER BY salary DESC LIMIT 5;`
This query sorts employees by salary from highest to lowest and returns the top 5 rows. `ORDER BY salary DESC` is the key step for ranking. `LIMIT 5` restricts output to five employees only. If there are salary ties at 5th position, this basic query still returns only five records; to include all ties, we would use advanced ranking functions. For beginner level, this is the standard expected answer. It is widely used in dashboards and HR reports for top earners, incentive reviews, and payroll analytics.

2. SQL query (simple method):
`SELECT MAX(salary) AS second_highest`
`FROM employees`
`WHERE salary < (SELECT MAX(salary) FROM employees);`
This first finds highest salary, then finds maximum among salaries lower than that value, which becomes second highest. It works well for basic interview questions and is easy to understand. If highest salary appears in multiple rows, this still correctly returns next distinct salary. If table has only one salary value, result can be null. Another modern method uses dense_rank window function, but this subquery approach is beginner-friendly and accepted in most SQL systems.

3. SQL query:
`SELECT MAX(price) AS max_price, MIN(price) AS min_price, AVG(price) AS avg_price, SUM(quantity) AS total_quantity`
`FROM products;`
This returns single-row summary containing highest price, lowest price, average price, and total quantity from all products. Aggregate functions (`MAX`, `MIN`, `AVG`, `SUM`) are used together for reporting. If any value is null, SQL aggregate rules generally ignore nulls (except `COUNT(*)`). This kind of query is common in inventory and sales dashboards to quickly understand overall stock and price range. Naming outputs with aliases improves readability in reports and frontend display.

4. SQL query:
`SELECT AVG(age) AS average_age FROM employees;`
This calculates average age of all employees in the table. `AVG` returns a decimal value in most databases, which can be rounded using `ROUND(AVG(age),2)` if needed. Null age values are ignored by default, so only valid numeric ages are considered. This is a simple aggregate query used in HR analytics, workforce planning, and demographic reporting. If you want average age by department, you can add `GROUP BY department_id`. But for the asked question, one-line query above is correct and sufficient.

5. To produce the shown output using Teacher and Task tables, operation is mainly **(i) EQUI JOIN** (and equivalent natural join behavior if column names align properly). Since task rows match teacher by teacher name/subject, we combine related tuples from both tables based on common attributes. Degree of final result depends on selected columns; if all columns from both are included without removing duplicates, degree increases by sum of both tables’ columns. Cardinality in given output is **9** rows (three teachers × three tasks each). So answer: join-based operation, degree depends on projection, and final cardinality = 9.

6. SQL queries:
`(a) SELECT * FROM Teacher t JOIN Task k ON t.Teacher_Name = k.TeacherName;`
`(b) SELECT k.CompletionDate, t.Subject FROM Teacher t JOIN Task k ON t.Teacher_Name = k.TeacherName;`
`(c) SELECT t.Teacher_Name, t.Subject, k.TaskName FROM Teacher t JOIN Task k ON t.Teacher_Name = k.TeacherName WHERE k.CompletionDate='31-05-2020';`
`(d) SELECT k.TaskName, t.Subject, k.CompletionDate FROM Teacher t JOIN Task k ON t.Teacher_Name = k.TeacherName;`
`(e) SELECT t.Teacher_Name, t.Subject, k.TaskName FROM Teacher t JOIN Task k ON t.Teacher_Name = k.TeacherName ORDER BY t.Teacher_Name;`
These are direct join queries linking teacher info with tasks using teacher name.

# UNIT -3

# WORKSHEET 1 (COMPUTER NETWORKS) - ANSWERS

## Multiple Choice Questions
1. **C** - 32 and 128 bits
2. **B** - To facilitate communication and resource sharing
3. **B** - To standardize network protocols and communication
4. **C** - Star
5. **B** - To connect different networks and manage data traffic between them
6. **B** - A binary digit, representing 0 or 1
7. **B** - Frequency Modulation (FM)
8. **A** - To protect against unauthorized access and malicious activities
9. **A** - Local Area Network (LAN)
10. **B** - To convert domain names to IP addresses

## Subjective Questions
1. The OSI model is important because it gives a clear structure for how network communication should happen, from sending raw bits to showing data in applications. It divides networking into seven layers, and each layer has a specific job. This makes learning, designing, and troubleshooting networks much easier. For example, if data is not reaching a website, engineers can check layer by layer instead of guessing. It also allows different companies to build devices and software that still work together using standard rules. In short, OSI is like a common language and roadmap that makes modern networking organized and easier to manage.

2. In a star topology, every device connects to one central hub or switch. It is easy to install, easy to expand, and simple to troubleshoot because each connection is separate. But if the central device fails, the whole network can stop. In a mesh topology, each device connects to many or all other devices. This gives very high reliability because if one link fails, data can use another path. The downside is cost and complexity, since many cables/links are needed. So star is best for normal offices and schools, while mesh is preferred in critical systems where uptime is very important.

3. A router is a network device that connects different networks and forwards data packets between them. It checks destination IP addresses and chooses the best path for the data to travel. For example, when you open a website, your home router sends your request from your local network to the internet and then routes the response back. Routers reduce unnecessary traffic by sending packets only where needed. They also improve efficiency using routing tables and can provide features like NAT, traffic control, and basic security filtering. Without routers, separate networks could not communicate properly, and internet access from local devices would not work smoothly.

4. A firewall is a security system that monitors incoming and outgoing network traffic and applies rules to allow or block it. Its main function is to stop unauthorized access while allowing safe communication. For example, it can block suspicious ports, malicious IP addresses, or unknown apps trying to access the network. Firewalls also help prevent attacks like malware spread and unauthorized remote login attempts. Some firewalls inspect packet content and application behavior, not just addresses. In organizations, firewalls are often placed between internal network and internet. In simple terms, a firewall works like a security guard checking what can enter or leave.

5. DNS (Domain Name System) is like the phonebook of the internet. Humans remember names like `google.com`, but computers communicate using IP addresses like `142.250.x.x`. DNS translates the domain name into the correct IP address so your browser can connect to the right server. Without DNS, users would need to memorize many numeric addresses, which is impractical. DNS also supports scalability because websites can change server IPs without changing domain names users type. It improves usability, speed (through caching), and overall internet convenience. So DNS is essential for simple, fast, and user-friendly web access.

6. Analog signals are continuous signals that vary smoothly over time, while digital signals use discrete values, usually 0 and 1. Example of analog: traditional FM radio waves and old telephone voice signals. Example of digital: computer data transfer, Wi-Fi packets, and modern mobile communication encoding binary data. Analog is natural and simple for some transmission types but more sensitive to noise. Digital is easier to store, process, compress, encrypt, and regenerate with less quality loss. That is why modern communication systems mostly use digital technology, even when carrying voice and video, because it is more reliable and efficient for long-distance and high-speed networks.

---

# WORKSHEET 2 (COMPUTER NETWORKS) - ANSWERS

## Multiple Choice Questions
1. **C** - Mesh
2. **D** - Unidirectional data flow
3. **B** - Data Link Layer
4. **D** - HTTPS
5. **B** - Simple to install and cost-effective
6. **A** - TCP/IP model
7. **D** - Allows for flexible device mobility
8. **D** - To establish a reliable, connection-oriented communication
9. **B** - Fiber Optic Cable
10. **B** - IP

## Subjective Questions
1. Star topology has a central device (usually a switch) to which all computers are connected. Its biggest advantage is easy management: if one cable fails, only one device is affected, not the whole network. It is also simple to add or remove nodes. Performance is usually good because links are independent. The main disadvantage is dependency on the central switch; if that switch fails, all communication stops. It also needs more cable than bus topology in some layouts. Star topology is very common in offices, schools, and labs because it balances reliability, cost, and ease of maintenance.

2. Bus topology uses a single main cable (backbone) to which all devices are attached. It is low-cost and easy to set up for small temporary networks because less cable is used. However, performance drops as more devices and traffic are added. If the backbone cable breaks, the whole network may fail. Troubleshooting can also be hard because one fault can affect everyone. Due to these limitations, bus topology is less common in modern enterprise setups. It is more suitable for very small environments, legacy systems, or basic learning demonstrations where simplicity and low setup cost are more important than scalability.

3. OSI model has seven layers, while TCP/IP model has four major layers. Both are layered approaches that divide communication tasks, making networking easier to understand and implement. OSI is mainly a conceptual reference model used for teaching and troubleshooting. TCP/IP is the practical model actually used on the internet. OSI separates presentation and session functions as distinct layers, but TCP/IP combines many application-related functions together. Both include transport and network-level communication concepts. In short, OSI is more detailed and theoretical, while TCP/IP is simpler and implementation-focused. They are similar in purpose but different in structure and real-world usage.

4. TCP ensures reliable communication by creating a connection before sending data and confirming delivery after sending. It breaks large data into segments, numbers them, and sends them in order. If any segment is lost, TCP retransmits it. It also checks for errors and controls flow so a fast sender does not overwhelm a slow receiver. This makes TCP suitable for applications where accuracy matters, such as web browsing, email, and file transfer. Although TCP has more overhead than UDP, it provides dependable end-to-end delivery. In short, TCP acts like a careful courier that tracks every packet and ensures correct arrival.

5. Transmission medium is the path through which data travels between devices. Wired media (like twisted pair, coaxial, and fiber optic) generally offer stable speed, lower interference, and better security because physical access is needed. Wireless media (like Wi-Fi, radio, satellite) provide mobility and easy deployment without cables. However, wireless is more affected by signal interference, distance, and security risks if not encrypted properly. Choice depends on use case: offices often use wired backbone plus wireless access for flexibility. Good network design usually combines both types to get reliability, speed, mobility, and cost efficiency according to business or personal requirements.

6. Protocols are rule sets that define how devices communicate on a network. Without protocols, devices would send data in incompatible formats and communication would fail. For example, IP handles addressing and routing, TCP ensures reliable delivery, HTTP handles web page requests, and DNS translates domain names to IP addresses. Protocols also define timing, error handling, and data format standards. Because all devices follow common protocol rules, equipment from different manufacturers can work together. In simple terms, protocols are like grammar in language: they ensure messages are understood correctly. They are the foundation that makes internet and networking possible.

---

# WORKSHEET 3 (COMPUTER NETWORKS) - ANSWERS

## Multiple Choice Questions
1. **A** - OSI model
2. **C** - Seven
3. **A** - Network Layer
4. **A** - HTTP
5. **A** - Encryption and decryption of data
6. **A** - Transport Layer
7. **C** - End-to-end communication and data segmentation
8. **A** - Physical Layer
9. **B** - DHCP
10. **A** - Simplicity and widespread adoption

## Subjective Questions
1. The OSI model has seven layers and is mainly used as a teaching and reference framework. It gives a detailed breakdown of communication tasks, such as presentation and session functions separately. TCP/IP model has four layers and is the practical architecture used by the internet. Both models support layered communication, modular design, and troubleshooting by isolating problems. OSI is more theoretical and detailed; TCP/IP is simpler and implementation-focused. Functionally they map similarly (application, transport, network, link/physical roles), but naming and grouping differ. In real networking, engineers mostly implement TCP/IP protocols but often use OSI terms when diagnosing problems.

2. The Application Layer in TCP/IP is where user-facing network services operate. It provides interfaces for applications to communicate over the network. Common protocols in this layer include HTTP/HTTPS (web browsing), SMTP/POP/IMAP (email), DNS (name resolution), and FTP (file transfer). For users, this is the most visible layer because activities like opening websites, sending emails, or downloading files happen here. It does not directly move bits on wires; instead, it prepares and requests data using application protocols. This layer is important because it connects software applications with lower networking layers, making internet services practical and easy to use.

3. The Transport Layer handles end-to-end communication between source and destination applications. Its key functions include segmentation of data, reassembly at receiver side, flow control, error recovery, and connection management. TCP and UDP are transport protocols with different behavior. TCP is connection-oriented and reliable, ensuring ordered delivery and retransmission of lost packets. UDP is connectionless, faster, and used where low delay is preferred over guaranteed delivery (like live streaming). By managing ports, transport layer also allows multiple applications to communicate at the same time on one device. It ensures correct process-to-process delivery, not just device-to-device delivery.

4. The Presentation Layer in OSI ensures data from one system can be correctly understood by another system, even if internal formats differ. Its main tasks include data translation, encryption/decryption, and compression/decompression. For example, one system may store text in one encoding while another uses a different encoding; this layer converts data into a common format. It also supports secure communication by handling encryption so unauthorized users cannot read data in transit. Although TCP/IP does not define it as a separate layer, its functions still exist in real applications and protocols. It improves compatibility, efficiency, and security of data exchange.

5. ICMP (Internet Control Message Protocol) is used for network control and error-reporting messages, not regular user data transfer. Routers and hosts use ICMP to report issues like destination unreachable, time exceeded, or network congestion hints. Tools like `ping` and `traceroute` rely on ICMP to test connectivity and path behavior. ICMP helps administrators diagnose whether a host is reachable and where packet loss occurs. In TCP/IP architecture, it works along with IP at the network layer level to support maintenance and troubleshooting. Without ICMP, finding routing and connectivity problems would be much harder in day-to-day network operations.

6. DHCP is important because it automatically assigns IP addresses and other network settings (subnet mask, gateway, DNS) to devices. Without DHCP, administrators would need to manually configure every device, which is slow and error-prone, especially in large networks. DHCP prevents duplicate IP conflicts by leasing unique addresses from a managed pool. It also simplifies changes; if network parameters update, clients can receive new settings automatically. This is very useful in offices, campuses, and Wi-Fi networks where devices join and leave frequently. In short, DHCP improves scalability, reduces configuration mistakes, and makes network management much easier.

---

# WORKSHEET 4 (COMPUTER NETWORKS) - ANSWERS

## Multiple Choice Questions
1. **A** - To divide a network into smaller, more manageable sub-networks
2. **A** - To identify the network portion of an IP address
3. **C** - To forward data packets between different networks
4. **D** - Distance-vector routing
5. **C** - To connect the network to the internet or another network
6. **B** - The size of the network address
7. **B** - It allows for more efficient use of IP addresses
8. **B** - To broadcast routing information to all devices in the network
9. **B** - Reduced routing table size
10. **A** - To convert private IP addresses to public IP addresses

## Subjective Questions
1. Subnetting means dividing one large IP network into smaller logical networks (subnets). This helps organize devices better and control traffic. In a large network, broadcast traffic can become heavy and reduce performance. By creating subnets, broadcasts stay within smaller groups, improving efficiency. Subnetting also improves security because departments (like HR, Finance, Lab) can be separated and controlled with routing/firewall rules. It also makes troubleshooting easier since issues are isolated to smaller segments. Another major advantage is better IP address utilization, especially with VLSM. In short, subnetting gives better performance, control, scalability, and cleaner network design.

2. A subnet mask tells which part of an IP address is network and which part is host. For example, in `192.168.1.10` with mask `255.255.255.0`, first three octets represent network, and last octet represents host. Devices with same network portion are in same subnet and can usually communicate directly. If destination is in another subnet, traffic goes to router/default gateway. So subnet mask directly affects how many subnets and hosts we can create. A longer network portion (like /26) gives more subnets but fewer hosts per subnet. A shorter one gives fewer subnets but more hosts. It is essential for correct routing decisions.

3. A router connects different networks and forwards packets based on destination IP addresses. It maintains routing information and selects best path using routing tables and routing protocols. In practical terms, it allows devices in one subnet to reach devices in another subnet or on the internet. Routers reduce unnecessary traffic by not forwarding every packet everywhere. They also support functions like NAT, access control lists, and quality-of-service policies. In enterprise networks, routers link branch offices, data centers, and internet edges. So their core role is intelligent packet forwarding, but they also improve network control, segmentation, security, and traffic efficiency.

4. Distance-vector routing shares route information as distance (metric, often hop count) and direction (next hop) with neighbors periodically. It is simpler and easier to configure, but convergence can be slower and may face routing loops (handled with split horizon, poison reverse, etc.). RIP is a common example. Link-state routing works by building a full map of network topology using link-state advertisements. Routers independently calculate shortest paths (often using Dijkstra algorithm). It converges faster and scales better for large networks but is more complex and resource-intensive. OSPF is a typical link-state protocol used in modern enterprise environments.

5. A default gateway is the router address a host uses when destination is outside its local subnet. If your computer wants to access another network or internet, it sends packets to this gateway. Without a default gateway, local communication may work, but external communication fails. It acts as the “exit door” from local network to broader networks. Correct default gateway configuration is essential in homes and organizations. Usually, it is the LAN interface IP of the local router. In routing logic, gateway handles next-hop forwarding so end devices do not need full routing tables. That is why it is crucial for inter-network communication.

6. VLSM (Variable Length Subnet Masking) allows using different subnet sizes in the same network according to actual host needs. This improves IP utilization because each subnet can be sized properly (for example, /30 for point-to-point links, /24 for larger LANs). Major benefits are reduced address waste, flexible design, and support for hierarchical routing. However, VLSM planning can be complex: administrators must calculate address blocks carefully and avoid overlap. Documentation and routing configuration must be accurate. For beginners, fixed-length subnetting is simpler, but VLSM is far more practical in real networks where departments and links need different subnet capacities.

---

# WORKSHEET 5 (COMPUTER NETWORKS) - ANSWERS

## Multiple Choice Questions
1. **C** - POP
2. **C** - Retrieving web pages
3. **C** - FTP
4. **B** - Sending emails
5. **B** - DNS
6. **B** - Resolving domain names to IP addresses
7. **B** - DHCP
8. **C** - File transfer between a client and a server
9. **D** - IMAP
10. **B** - Assigning IP addresses dynamically to devices

## Subjective Questions
1. SMTP, POP, and IMAP are email protocols with different roles. SMTP is used to send emails from sender to mail server and between mail servers. POP (usually POP3) is mainly for downloading emails from server to one device, often removing them from server after download. IMAP keeps emails on server and synchronizes folders/messages across multiple devices, which is better for modern usage (phone + laptop + webmail). In short, SMTP handles outgoing mail transfer, while POP/IMAP handle incoming mail access. POP is simpler, IMAP is more flexible for multi-device users and centralized server-based mailbox management.

2. DNS translates domain names into IP addresses so users can access websites using readable names instead of numbers. It is distributed and hierarchical, with root servers, TLD servers, and authoritative servers working together. DNS caching improves speed by storing recent query results. It also supports services like load balancing and mail routing through record types (A, AAAA, CNAME, MX, etc.). Without DNS, internet usability would be very poor because people would need to remember raw IP addresses for every site. So DNS is essential for performance, convenience, and scalable internet operation across billions of devices and domains.

3. FTP is a protocol used to transfer files between a client and server over a network. Key features include upload/download support, authentication with username/password, directory listing, and file management operations. It is useful for website deployment, backup transfer, and moving bulk files between systems. Traditional FTP is not encrypted, so credentials and data can be exposed. Secure alternatives like FTPS and SFTP are preferred in modern environments. FTP is still important in many legacy and controlled environments due to simplicity. In basic networking study, FTP is a classic example of application-layer protocol focused on file exchange.

4. DHCP automatically assigns IP addresses and related settings (subnet mask, gateway, DNS) to devices when they join a network. This removes the need to configure each device manually, which saves time and reduces mistakes. DHCP uses lease-based assignment, meaning addresses are temporarily assigned and renewed as needed. It helps avoid IP conflicts because server tracks used addresses in a pool. In schools, offices, and public Wi-Fi, DHCP makes network administration much easier as users connect and disconnect frequently. Overall, DHCP simplifies deployment, supports scalability, and keeps network addressing organized with minimal human effort.

5. HTTP and FTP are both application-layer protocols but used for different purposes. HTTP is mainly for web communication—browsers requesting web pages, images, scripts, and APIs from web servers. FTP is specifically for file transfer operations such as upload/download and directory management. HTTP is stateless request-response and now commonly secured as HTTPS. FTP traditionally uses separate control/data channels and is often replaced by secure variants for safety. In everyday use, HTTP powers website access, while FTP is used more in administration, hosting, or batch file movement. So HTTP is web-content focused; FTP is file-transfer focused.

6. DNS affects internet security and privacy because users trust it to reach correct destinations. If DNS is attacked or poisoned, users can be redirected to fake malicious sites (phishing). DNS queries can also reveal browsing behavior if not protected. Security improvements include DNSSEC (to validate authenticity of DNS records) and encrypted DNS methods like DoH/DoT (to reduce interception). Organizations also use DNS filtering to block known malicious domains. So DNS is not only a convenience service; it is a major security layer. Protecting DNS infrastructure helps prevent fraud, malware delivery, and privacy leakage.

7. POP and IMAP both retrieve emails from server, but behavior differs. POP usually downloads emails to local device and may remove them from server, which works for single-device use and offline storage. IMAP keeps mail on server and synchronizes read/unread status, folders, and deletions across devices. That makes IMAP better for users who access email from phone, laptop, and webmail together. POP can reduce server storage needs but may create device-specific copies. IMAP needs stable internet for full synchronization but gives better consistency and flexibility. In modern usage, IMAP is generally preferred for convenience and multi-device management.

8. DHCP dynamically assigns IP addresses through a simple process often described as DORA: Discover, Offer, Request, Acknowledge. A new device first broadcasts a discover message, DHCP server offers an available IP, device requests one offer, and server acknowledges with lease details. Along with IP, it sends subnet mask, gateway, and DNS settings. Because allocation is centralized, DHCP prevents two devices from getting same IP at the same time, reducing conflicts. It also reuses addresses efficiently when devices disconnect. This automated process is essential in dynamic environments like offices and campus Wi-Fi where many devices join frequently.
