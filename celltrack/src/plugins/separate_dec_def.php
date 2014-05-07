#!php
<?
$f = fopen("php://stdin","r");
$dec=$def="";
while($s = trim(fgets($f))){
    $ss = explode(";",$s);
    foreach($ss as $s){
        if (preg_match("/([^=\n]+[\s\*]+)([^=\n\s]+)\s*=\s*([^\n]+);/",$s,$ms)){
            $dec.="{$ms[1]}{$ms[2]};\n";
            $def.="{$ms[2]} = {$ms[3]};\n";
        }
    }
}
echo "$dec\n\n$def";