import math
ab = int(input())
bc = int(input())
angle_rad = math.atan(ab / bc)
angle_deg = round(math.degrees(angle_rad))
print(str(angle_deg) + chr(176))
