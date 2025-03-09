import pandas as pd

# Load the Excel file
file_path = "teams.xlsx"  # Change this to your file name
df = pd.read_excel(file_path)

# Assuming there's a column named "University" that differentiates teams
grouped = df.groupby("Institution Name")

# # Save each university's team in a separate CSV file
# for university, data in grouped:
#     filename = f"{university.replace(' ', '_')}.csv"  # Remove spaces in filename
#     data.to_csv(filename, index=False)
#     print(f"Saved: {filename}")


print(len(grouped))