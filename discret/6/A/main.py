input = open('nextvector.in', 'r')
 
input_str = input.read()

input_str = input_str.rstrip("\n\r")

input.close()
 
n = int(input_str, 2)
 
if n>0:
	prev=str(bin(n-1))[2:]
	while len(prev)<len(input_str):
		prev='0'+prev
else:
	prev='-'

next = str(bin(n+1))[2:]
if len(input_str)<len(next):
	next='-'
else:
	while len(next)<len(input_str):
		next='0'+next
 
output = open('nextvector.out', 'w')
 
print(prev, file = output)
print(next, file = output)
 
output.close()