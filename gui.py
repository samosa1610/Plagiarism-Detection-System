import tkinter as tk
from tkinter import filedialog, messagebox, scrolledtext
import subprocess
import os

def browse_file(entry):
    file_path = filedialog.askopenfilename(filetypes=[("Text files", "*.txt")])
    if file_path:
        entry.delete(0, tk.END)
        entry.insert(0, file_path)

def run_checker():
    file1 = entry1.get()
    file2 = entry2.get()

    if not os.path.exists(file1) or not os.path.exists(file2):
        messagebox.showerror("Error", "Both files must be selected.")
        return

    # Copy files to expected names
    os.system(f"cp '{file1}' file1.txt")
    os.system(f"cp '{file2}' file2.txt")

    # Run shell script
    try:
        subprocess.run(["bash", "run.sh"], check=True)
    except subprocess.CalledProcessError as e:
        messagebox.showerror("Error", f"run.sh failed: {e}")
        return

    # Show results
    if os.path.exists("results.txt"):
        with open("results.txt", "r") as f:
            output_text.delete("1.0", tk.END)
            output_text.insert(tk.END, f.read())
    else:
        messagebox.showerror("Error", "results.txt not found.")

# GUI setup
root = tk.Tk()
root.title("Plagiarism Checker GUI")

tk.Label(root, text="File 1:").grid(row=0, column=0, sticky="e")
entry1 = tk.Entry(root, width=50)
entry1.grid(row=0, column=1)
tk.Button(root, text="Browse", command=lambda: browse_file(entry1)).grid(row=0, column=2)

tk.Label(root, text="File 2:").grid(row=1, column=0, sticky="e")
entry2 = tk.Entry(root, width=50)
entry2.grid(row=1, column=1)
tk.Button(root, text="Browse", command=lambda: browse_file(entry2)).grid(row=1, column=2)

tk.Button(root, text="Run Plagiarism Check", command=run_checker).grid(row=2, column=1, pady=10)

output_text = scrolledtext.ScrolledText(root, width=80, height=25)
output_text.grid(row=3, column=0, columnspan=3)

root.mainloop()
