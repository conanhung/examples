<?
if (sizeof($argv) < 2){
    echo "usage:\naddNewPlugin.php <name>";
}
$wd = dirname(__FILE__);
$name = $argv[1];

$lines = explode("\n",file_get_contents("$wd/../MyFrame.h"));
$i=0;
while(strpos($lines[$i++],"\tvoid OnFindContours")===FALSE);
while(trim($lines[$i++]));
array_splice($lines, $i-1, 0, "\tvoid On$name( wxCommandEvent& event );");
file_put_contents("$wd/../MyFrame.h", implode("\n",$lines));


$lines = explode("\n",file_get_contents("$wd/../MyFrame.cpp"));
$i=0;
while(strpos($lines[$i++],"DEFINE_ONPLUGIN")===FALSE);
while(trim($lines[$i++]));
array_splice($lines, $i-1, 0, "DEFINE_ONPLUGIN( $name )");
file_put_contents("$wd/../MyFrame.cpp", implode("\n",$lines));
