# 🔁 POLYMORPHISM — LAST MINUTE REVISION NOTES (C++)

## 🔹 Definition

**Polymorphism** ka matlab hai:

> **One interface, many forms**
> Yani same function name, lekin different behavior.

---

## 🔹 Types of Polymorphism

### 1️⃣ Compile-Time Polymorphism

* Decision **compile time** pe hota hai
* **Static Binding**
* Examples:

  * Function Overloading
  * Operator Overloading

📌 Is mein compiler pehle hi decide kar leta hai konsa function call hoga.

---

### 2️⃣ Run-Time Polymorphism ⭐ (IMPORTANT)

* Decision **run time** pe hota hai
* **Dynamic Binding**
* Achieve hota hai:

  * Function Overriding
  * **Virtual Functions**
  * **Base class pointer**

📌 Yehi **real / proper polymorphism** hai (oral mein mostly isi ki baat hoti hai).

---

## 🔹 Function Overloading

* Same function name
* Different parameters
* Compile time pe decide hota hai

Example:

```
add(int, int)
add(float, float)
```

---

## 🔹 Function Overriding

* Same function name
* Same parameters
* Base class + Derived class

⚠️ **Sirf overriding se polymorphism nahi banti**

---

## 🔹 Virtual Function ⭐

* Function jo **run-time polymorphism** allow karta hai
* Base class mein `virtual` keyword use hota hai

📌 Virtual function ki wajah se function call **object ke type** ke basis pe hoti hai, na ke pointer ke type pe.

---

## 🔹 Static Binding

* Function call **compile time** pe decide hoti hai
* Virtual function use nahi hota
* Fast hoti hai

🧠 One-liner:

> Static binding mein compiler decide karta hai konsa function chalega.

---

## 🔹 Dynamic Binding ⭐

* Function call **run time** pe decide hoti hai
* Virtual function + base class pointer
* Object ka type decide karta hai konsa function chalega

🧠 One-liner:

> Dynamic binding mein function call run time pe object ke type ke basis pe hoti hai.

---

## 🔹 Key Rule (EXAM MANTRA 🧠)

> **Overriding ≠ Polymorphism**
> **Virtual + Base Pointer = Polymorphism**

---

## 🔹 Need of Polymorphism

* Code reusability
* Flexibility
* Easy extension (new classes without changing old code)
* Real-world problems ko easily model karna

---

## 🔹 Simple Example (Run-time Polymorphism)

```
Shape *s;
Circle c;
Square sq;

s = &c;   // Circle ka draw()
s->draw();

s = &sq;  // Square ka draw()
s->draw();
```

📌 Same pointer, different behavior = polymorphism.

---

## 🔹 One-Line Oral Answers

* **Polymorphism:** One interface, many forms
* **Static Binding:** Compile time decision
* **Dynamic Binding:** Run time decision
* **Virtual Function:** Enables run-time polymorphism

---

✅ **Itna hi syllabus hai polymorphism ka — no extra tension.**
