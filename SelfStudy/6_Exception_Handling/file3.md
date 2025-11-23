# EXCEPTION REPORT

## Title  
Analysis of Exceptions in C++ Program

## Course  
Object Oriented Programming

## Submitted By  
**Momina Imran**

---

## 1. invalid_argument Exception

**Line Number:** 11  
**Exception Name:** `invalid_argument`

**Reason:**  
An integer variable `age` is assigned a negative value (-5). Since a negative age is logically invalid, the program manually throws `invalid_argument` to indicate improper input.

---

## 2. out_of_range Exception

**Line Number:** 19  
**Exception Name:** `out_of_range`

**Reason:**  
A vector with three elements is accessed using index `5`. The `at()` function checks bounds and throws `out_of_range` when the index is beyond the allowed range (0–2).

---

## 3. length_error Exception

**Line Number:** 27  
**Exception Name:** `length_error`

**Reason:**  
A vector tries to reserve memory larger than its maximum allowable size using `v.reserve(v.max_size() + 1)`. Since the requested size cannot be allocated, the vector throws `length_error`.

---

## 4. overflow_error Exception

**Line Number:** 34  
**Exception Name:** `overflow_error`

**Reason:**  
The code manually throws this exception to simulate a mathematical overflow condition and demonstrate how such runtime errors can be handled.

---

## 5. underflow_error Exception

**Line Number:** 41  
**Exception Name:** `underflow_error`

**Reason:**  
This exception is intentionally thrown to represent a mathematical underflow situation and to show how the program manages such errors.

---

## 6. runtime_error Exception

**Line Number:** 48  
**Exception Name:** `runtime_error`

**Reason:**  
A generic runtime error is thrown manually to demonstrate how general exceptions can be raised and caught during program execution.

---

## 7. bad_alloc Exception

**Line Number:** 55  
**Exception Name:** `bad_alloc`

**Reason:**  
The program attempts to allocate an extremely large memory block using  
`new int[9999999999999]`. Since the system cannot provide that much memory, the `new` operator throws `bad_alloc`.

---
