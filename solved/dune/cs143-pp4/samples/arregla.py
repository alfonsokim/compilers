import os
import glob

for out_name in glob.glob("*.out"):
    new_name = "%s.old" % out_name.split(".")[0]
    os.rename(out_name, new_name)
    in_file = open(new_name, 'r')
    out_file = open(out_name, 'w')
    print '-'*4
    for c, line in enumerate(in_file):
        if c >= 4: print >> out_file, line.strip().replace("/usr/class/cs143/bin/", "/usr/share/spim/")
    out_file.close()
    in_file.close()