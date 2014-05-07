#!php
<?
$f = fopen("php://stdin","r");
$dec=$def="";
while($s = trim(fgets($f))){
    $ss = preg_split("/[;,]/",$s);
    foreach($ss as $s){
        if (preg_match("/(\S+)\s+(\S+)\s*/",$s,$ms)){
            $dec.="{$ms[2]}, ";
        }
    }
}
echo "$dec\n\n$def";