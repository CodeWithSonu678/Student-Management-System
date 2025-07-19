# 🎓 Student Management System in C

This is a simple and efficient **console-based Student Management System** written in the C programming language. It allows you to **add**, **view**, **search**, **update**, and **delete** student records, and also export the data into a **CSV file** for external use.

---

## ✅ Features

- ➕ Add new student record  
- 📋 View all student records  
- 🔍 Search student by roll number or name  
- ✏️ Update student information  
- ❌ Delete a student record  
- 📄 Export data to `CSV` format  
- 💾 File handling support for storing records

---

## 📁 File Structure

```bash
StudentManagementSystem/
│
├── student_management_system.c            # Main C program
├── records.txt      # Data file (for storing student records)
├── records.csv       # Exported CSV file
└── README.md
```

---

## ▶️ How to Compile and Run

### 🔹 Using Terminal (gcc):

```bash
gcc main.c -o student
./student
```

### 🔹 Using Code::Blocks or Other IDE:

1. Open Code::Blocks  
2. Create a new Console Project → Language: C  
3. Replace the default `main.c` with your code  
4. Press **F9** or click **Build & Run**

---

## 🛠️ Technologies Used

- **C language**
- **File Handling (`fopen`, `fprintf`, `fscanf`)**
- **Basic I/O and String Handling**

---

## 📌 Sample CSV Output

```
Roll,Name,Course,Marks
101,John Doe,Math,85
102,Jane Smith,Physics,91
```

---

## 🧑‍💻 Author

- **Name:** Sonu Yadav  
- **GitHub:** [@CodeWithSonu678](https://github.com/CodeWithSonu678)

---

