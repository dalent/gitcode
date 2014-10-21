import time
import subprocess
import sys
if len(sys.argv) != 3:
    print "cmd argu"
    exit(0)

cmd = sys.argv[1:]
print cmd
proc = subprocess.Popen(cmd, stdout=subprocess.PIPE)
for line in proc.stdout:
    print line.rstrip()
