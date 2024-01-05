from tkinter import *
import requests
import tkinter as tk
import tkinter.font as font
from tkinter import ttk
from tkinter import Canvas
import json
from datetime import datetime

ip_address = "http://192.168.18.20:8080"




win = Tk()
win.geometry("1920x1080")
win.attributes('-fullscreen', True)
drop_var = StringVar()
rid_drop_var = StringVar()
eid_drop_var = StringVar()
description_var = StringVar()
loc_var = StringVar()
type_drop_client = StringVar()
eid_var = StringVar()
rid_var = StringVar()
report_summary = []

def clear_frame():
   for widgets in frame.winfo_children():
      widgets.destroy()

def get_description_type():
    global report_summary
    headers = {'Content-type': 'application/json'}
    
    #fetches the description on the main client page
    description = description_var.get()
    if description == "Please write a brief description to help us assist you":
       description = "NA"
    print("Description entered:", description)
    emergency_type = type_drop_client.get()
    print("Type entered:", emergency_type)
    current_time = datetime.now()
    time_string = current_time.strftime("%Y-%m-%d %H:%M:%S")
    data= {}
    data["description"] = description
    data["type"] = emergency_type
    data["created-time"] = time_string
    json_object = json.dumps(data)
    url =  ip_address + "/emergency-request/raise"
    response = requests.post(url, data=json_object, headers = headers)
    if response.status_code == 200:
       print('Raise Request successful! ', response.text)
       parsed_data = json.loads(response.text)
       id_assigned = parsed_data["id"]
       desc_assigned = parsed_data["description"]
       type_assigned = parsed_data["type"]
       date_assigned = parsed_data["created-time"]
       temp_list = [id_assigned, desc_assigned, type_assigned, date_assigned] 
       report_summary.extend(temp_list)
       
    else:
       print('Raise Request failed with status code:', response.status_code)
    
'''def get_client_optional():
    location = loc_var.get()
    print("Location entered:", locaton)
    emergency_type = type_drop_client.get()
    print("Type entered:", emergency_type)'''

def get_allocation():
   headers = {'Content-type': 'application/json'}
   eid = eid_var.get()
   print("EID entered:", eid)
   rid = rid_var.get()
   print("RID entered:", rid)
   data= {}
   data["id"] = eid
   data["personnel-assigned"] = rid
   json_object = json.dumps(data)
   url =  ip_address + "/emergency-request/assign"
   response = requests.post(url, data=json_object, headers = headers)
   if response.status_code == 200:
       print('Assignment successful! ', response.text)
   else:
       print('Assignment Request failed with status code:', response.status_code)
      

   

def clear_textbox(tb):
    #passed text_box object as a variable in the parameter
    tb.delete(0, 'end')
    
def start_window():
    Label(frame,text="Emergency Responder \nSystem", font=('Helvetica',70)).place(x = 60, y = 170, height=210, width=1200)
    Button(frame, text = "EXIT", font = ('Helvetica', 18), bg = "#BEBDB8", command=lambda: win.destroy()).place(x = 1050, y = 650, height = 50, width = 150)
    Button(frame, text = "Client", font=('Helvetica',30), bg = "green", command=lambda: [clear_frame(), open_client()]).place(x = 550, y = 450, height=60, width=200)
    Button(frame, text = "Operator", font=('Helvetica',30), bg = "orange", command=lambda: [clear_frame(), open_operator()]).place(x = 250, y = 450, height=60, width=200)
    Button(frame, text = "Personnel", font=('Helvetica',30), bg = "#ADD8E6").place(x = 850, y = 450, height=60, width=200)

def open_client():
    type_drop_option = ["Other", "Domestic Violence", "Fire", "Medical", "Industrial Accident", "Security threats", "Infrastructure Accident", "Transport Accident", "Gas Leaks", "Search and Rescue"]

    Label(frame,text="Client Interface", font=('Helvetica',30)).place(x = 300, y = 0, height=80, width=700)
    Button(frame, text = "EXIT", font = ('Helvetica', 18), bg = "#BEBDB8", command=lambda: win.destroy()).place(x = 1050, y = 650, height = 50, width = 150)
    Button(frame, text = "Back", font = ('Helvetica', 18), bg = "#BEBDB8", command=lambda: [clear_textbox(brf_desc), clear_frame(), drop.destroy(), start_window()]).place(x = 100, y = 650, height = 50, width = 150)
    Button(frame, text="RAISE EMERGENCY", font=('Helvetica',70), bg = "#FF2800", command = lambda: [get_description_type(), clear_textbox(brf_desc), drop.destroy(), clear_frame(), open_client_completion()]).place(x = 0, y = 350, height = 200, width = 1300)
    brf_desc = Entry(frame, font=('Helvetica', 20), textvariable = description_var, bg="#FFCCCC")
    brf_desc.insert(0, "Please write a brief description to help us assist you")
    brf_desc.place(x=80, y=150, height=110, width=700)
    Label(frame, text = "Emergency Type", font = ('Helvetica', 15), bg = "#FFFDD0").place(x = 800, y = 180, height = 50, width = 250)

    global type_drop_client
    global drop_var
    drop_var.set(type_drop_option[0])
    def on_option_select(event):
        global type_drop_client
        type_drop_client.set(drop_var.get())
    drop = OptionMenu(win, drop_var, *type_drop_option)
    drop.place(x = 1070, y = 180, width = 180, height = 50)
    drop.bind("<Configure>", on_option_select)
    drop.config(bg="#FFFDD0")
    
def open_client_completion():
    global report_summary
    #screen on report of emergency
    Label(frame,text="Your report has been forwarded to \nthe emergency operators\nHelp will arrive shortly", font=('Helvetica',45)).place(x = 150, y = 40, height=270, width=1000)
    Label(frame,text=f"Here is the report summary:\n\nID number: {report_summary[0]}\nDescription: {report_summary[1]}\nEmergency type: {report_summary[2]}\nDate created: {report_summary[3]} ", font=('Helvetica',17)).place(x = 250, y = 280, height = 270, width = 800)

    Button(frame, text = "EXIT", font = ('Helvetica', 18), bg = "#BEBDB8", command=lambda: win.destroy()).place(x = 1050, y = 650, height = 50, width = 150)
    #Button(frame, text = "Finish", font = ('Helvetica', 18), bg = "#BEBDB8", command=lambda: [get_client_optional(), clear_textbox(location), drop.destroy(), clear_frame(), start_window()]).place(x = 800, y = 650, height = 50, width = 150)
    #Label(frame, text = "Location", font = ('Helvetica', 15), bg = "#FFFDD0").place(x = 80, y = 400, height = 50, width = 150)
    #Label(frame, text = "Emergency Type", font = ('Helvetica', 15), bg = "#FFFDD0").place(x = 750, y = 400, height = 50, width = 250)
    Button(frame, text = "Finish", font = ('Helvetica', 18), bg = "#0A2472", fg="white", command=lambda: [clear_frame(), start_window()]).place(x = 100, y = 650, height = 50, width = 600)

    #location = Entry(frame, font=('Helvetica', 15), textvariable = loc_var, bg="#FFFDD0")
    #location.insert(0, "")
    #location.place(x=230, y=400, height=50, width=250)
    
    '''global type_drop_client
    global drop_var
    drop_var.set(type_drop_option[0])
    def on_option_select(event):
        global type_drop_client
        type_drop_client.set(drop_var.get())
    drop = OptionMenu(win, drop_var, *type_drop_option)
    drop.place(x = 1050, y = 400, width = 180, height = 50)
    drop.bind("<Configure>", on_option_select)
    drop.config(bg="#FFFDD0")'''

def open_operator():
   Label(frame,text="LIVE FEED", font=('Helvetica',28)).place(x = 300, y = 0, height=80, width=200)
   Button(frame, text = "EXIT", font = ('Helvetica', 15), bg = "#0A2472", fg="white", command=lambda: win.destroy()).place(x = 270, y = 650, height = 35, width = 150)
   Button(frame, text = "Back", font = ('Helvetica', 15), bg = "#0A2472", fg="white", command=lambda: [clear_frame(), drop1.destroy(), drop2.destroy(), start_window()]).place(x = 80, y = 650, height = 35, width = 150)


   tv = ttk.Treeview(frame, columns = (1,2,3,4), show  = "headings", height = "8")
   tv.pack(padx = 10, pady = 100, anchor = tk.W)

   tv.column("# 1",anchor=CENTER, stretch=NO, width=150)
   tv.heading("# 1", text="Emergency ID")
   tv.column("# 2", anchor=CENTER, stretch=NO, width = 250)
   tv.heading("# 2", text="Description")
   tv.column("# 3", anchor=CENTER, stretch=NO, width = 200)
   tv.heading("# 3", text="Date created")
   tv.column("# 4", anchor=CENTER, stretch=NO, width = 120)
   tv.heading("# 4", text="Type")
   #get the 2D list of object attributes
   datav = [["12HYUENC983JCK", "Electrocution at St Mary's Lane", "2024-01-05 23:19:01", "Industrial Accident"]]
   for i in datav:
       tv.insert('', 'end', values = i)
   
   tw = ttk.Treeview(frame, columns = (1,2,3,4), show  = "headings", height = "8")
   tw.pack(padx = 10, pady = 0, anchor = tk.W)

   tw.column("# 1",anchor=CENTER, stretch=NO, width=100)
   tw.heading("# 1", text="Personnel ID")
   tw.column("# 2", anchor=CENTER, stretch=NO, width = 150)
   tw.heading("# 2", text="Personnel Name")
   tw.column("# 3", anchor=CENTER, stretch=NO, width = 200)
   tw.heading("# 3", text="Pending Requests")
   tw.column("# 4", anchor=CENTER, stretch=NO, width = 200)
   tw.heading("# 4", text="Status")
   #get the 2D list of personnel attributes
   dataw = [["WAP5932", "Michael Reilly", 3, "Engaged"], ["WAP3290", "Lawson Blake", 0, "Standby"], ["WAP3029", "Michael Sandears", 5, "Standby"]]
   for i in dataw:
      tw.insert('', 'end', values = i)

   #line drawing
   line1 = tk.Frame(frame, width=2, height=800, bg="black")
   line1.place(x = 750, y = 0)
   Label(frame, text = "Allocation", font = ('Helvetica', 18), bg = "#FFCBA4").place(x = 752, y = 20, height = 50, width = 550)
   Label(frame, text = "Deallocation", font = ('Helvetica', 18), bg = "#C7C6C1").place(x = 752, y = 370, height = 50, width = 550)
   Label(frame, text = "EID", font = ('Helvetica', 18), bg = "#FFCBA4").place(x = 780, y = 100, height = 50, width = 250)
   Label(frame, text = "RID", font = ('Helvetica', 18), bg = "#FFCBA4").place(x = 780, y = 180, height = 50, width = 250)
   Button(frame, text = "Raise \nAllocation", font = ('Helvetica', 18), bg = "#FFCBA4", command = lambda: get_allocation()).place(x = 910, y = 260, height = 80, width = 250)

   
   Label(frame, text = "EID", font = ('Helvetica', 18), bg = "#C7C6C1").place(x = 780, y = 450, height = 50, width = 250)
   Label(frame, text = "RID", font = ('Helvetica', 18), bg = "#C7C6C1").place(x = 780, y = 530, height = 50, width = 250)
   Button(frame, text = "Deallocate", font = ('Helvetica', 18), bg = "#C7C6C1").place(x = 910, y = 620, height = 80, width = 250)

   global eid_drop_var
   global eid_var
   #get eid list
   eid_list = ["12HYUENC983JCK"]
   eid_var.set(eid_list[0])
   def on_option_select(event):
      global eid_var
      eid_drop_var.set(eid_var.get())
   drop1 = OptionMenu(win, eid_var, *eid_list)
   drop1.place(x = 1050, y = 100, width = 180, height = 50)
   drop1.bind("<Configure>", on_option_select)
   drop1.config(bg="#FFCBA4")

   global rid_drop_var
   global rid_var
   #get eid list
   rid_list = ["WAP5932", "WAP3290", "WAP3029"]
   rid_var.set(rid_list[0])
   def on_option_select(event):
      global rid_drop_var
      rid_drop_var.set(rid_var.get())
   drop2 = OptionMenu(win, rid_var, *rid_list)
   drop2.place(x = 1050, y = 180, width = 180, height = 50)
   drop2.bind("<Configure>", on_option_select)
   drop2.config(bg="#FFCBA4")

   



    
frame = Frame(win)
frame.pack(side = "top", expand = True, fill = "both")
start_window()
win.mainloop()

