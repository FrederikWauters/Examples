ms = "tomatensaus met balleke"
ss = ms.split(" ")
rs=""
for x in xrange(0,3):
	if x > 0 :
		rs+=" "
	rs+=ss[x]
print rs

#for i in  xrange(5):
#	print i+1

for x in xrange(10):
    # Check if x is even
    if x % 2 == 0:
        continue
    print x

def my_function_with_args(username, greeting):
    print "Hello, %s , From My Function!, I wish you %s"%(username, greeting)

my_function_with_args("John Doe", "a great year!")
