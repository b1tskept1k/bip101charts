set datafile sep ","
set timefmt "%s"
set xdata time
set format x "%Y"
set format x "%Y-%m-%d"
set format y '%.0s%cB'
set yrange [0:]

# output settings
set term png
set output "1year.png"
set xtics rotate

# generate the plots
set title "BIP101 Block Size - 1 Year"
plot 'bip101.csv' every ::::365 using 1:2 with lines title 'Max Block Size'
set output "3year.png"
set title "BIP101 Block Size - 3 Year"
plot 'bip101.csv' every ::::(3*365) using 1:2 with lines title 'Max Block Size'
set output "10year.png"
set title "BIP101 Block Size - 10 Year"
plot 'bip101.csv' every ::::(10*365) using 1:2 with lines title 'Max Block Size'
set output "30year.png"
set title "BIP101 Block Size - 30 Year"
plot 'bip101.csv' every ::::(30*365) using 1:2 with lines title 'Max Block Size'
