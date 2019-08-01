#/bin/bash
FT_LINE1=8
FT_LINE2=16
export FT_LINE1
export FT_LINE2

cat /etc/passwd | sed '1d; n; d'|  grep -v '^$\|^\s*\#' | sed '1!G;h;$!d' | sed 's/:.*//' | rev | awk "NR>= $FT_LINE1 &&NR<= $FT_LINE2 " | tr '\n' ', '
echo "."