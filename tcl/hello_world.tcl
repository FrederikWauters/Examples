#!/usr/bin/tclsh

puts "Hello word example: "



proc helloworld {} { #this bracket has to be on this line!
  puts "Hello World!"
} 
helloworld ; #comment after need semicolumn

puts "\n\n"

#lists#
#set a {1 1 2 baba}
#puts [lindex $a 3]

#ass arrays (dict)#
#set value(b) 2
#set value(a) 2
#puts $value(a)

#floats and ints, the usual#
#set variableA "10"
#set result [expr $variableA / 9]
#puts $result#!/usr/bin/tclsh

#puts "Hello World!" 
#set result [expr $variableA / 9.0]
#puts $result
#set variableA "10.0"
#set tcl_precision 5
#set result [expr $variableA / 9]	
#puts $result

set myList {red green blue "light orange"}
puts [lindex $myList 3]

#c like operators#
set a 10;
set b [expr $a == 1 ? 20: 30]
puts "Value of b is $b\n"

#loop over array#
set values(0) 1
set values(1) 2
set values(2) 3
puts [array names values]
#set values { 1 2 3 } #doesnt work for some reason
for {set index 0} { $index < [array size values] } {incr index} {
  puts "values: $values($index)" 
  }

set my_name(first) "free"
set my_name(last) "WW"
puts [array names my_name]
foreach key [array names my_name] {
  puts "my_name($key) : $my_name($key)"
}

set filename "data.txt"
set myfile [open $filename r]
set file_data [read $myfile]
puts $file_data
close $myfile

