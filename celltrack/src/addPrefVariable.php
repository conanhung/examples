<?
if (sizeof($argv) < 3){
    echo "usage:\naddPrefVariables.php remove|<type> <name>";
    getTypes("none");
}
function getTypes($in){
    $types = array('radio'=>array('bool','VALUE'),
                   'combo'=>array('int','SELECTION'),
                   'check'=>array('bool','VALUE'),
                   'text'=>array('wxString','VALUE'),
                   'spin'=>array('int','VALUE'),
                   'color'=>array('wxString','COLOUR'),
                   'notebook'=>array('int','SELECTION')
                  );
    if(!isset($types[$in]))
        die("$in is not a defined component.\n Use one of: ". implode(", ",array_keys($types))."\n");
    return $types[$in];
}
$vars = array();
$i=1;
$removemode=false;
if ($argv[$i]=='remove'){
    $removemode=true;
    $i++;
}
for (; $i<sizeof($argv); $i+= ($removemode ? 1 : 2)){
    if($removemode) {
        $name = $argv[$i];
    }
    else{
        list($type, $ctype) = getTypes($argv[$i]);
        $name = $argv[$i+1];
        $isint = in_array($type,array('int'));
    }
    $removed = false;
    foreach(array("Preferences.h","Preferences.cpp") as $file){
        $lines = explode("\n",file_get_contents($file));
        for($j=0; $j<sizeof($lines); $j++){
            if (strpos($lines[$j], $name)!==FALSE){
                if($removemode){
                    array_splice($lines, $j, 1);
                    $j--;
                    $removed = true;
                }
                else
                    die("$name already appears in $file:$j");
            }
        }
        if ($removemode && $removed)
            file_put_contents($file, implode("\n",$lines));
    }
    if($removemode)
        continue;
    $define_pref[] = "\tDEFINE_PREF_VARIABLE($type, $name)";
    $declare_pref[] = "DECLARE_PREF_GET($type, $name)";
    $init_value[] = "\tSET_CONTROL_$ctype($name)";
    $init_default[] = "\tSET_CONTROL_{$ctype}_DEFAULT($name)";
    $onsave[] = "\tGET_CONTROL_{$ctype}($name)";
    $onsave_config[] = "\tPREF_WRITE_VALUE".($isint ? '_LONG':'')."($name)";
    $pref_init[] = "\tPREF_INIT_".($type=='bool' ? 'BOOL' :
                                   ($ctype=='COLOUR' ? 'COLOUR' :
                                    ($ctype=='SELECTION' ? 'SELECTION' :
                                     ($isint ? 'VALUE_LONG' :
                                      $ctype ) ) ) )."($name)";
}

if ($removemode)
    exit();

$lines = explode("\n",file_get_contents("Preferences.h"));
//file_put_contents("Preferences_backup.h", implode("\n",$lines));
$i=0;
while(strpos($lines[$i++],"\tDEFINE_PREF_VARIABLE")===FALSE);
while(trim($lines[$i++]));
array_splice($lines, $i-1, 0, $define_pref);
file_put_contents("Preferences.h", implode("\n",$lines));


$lines = explode("\n",file_get_contents("Preferences.cpp"));
//file_put_contents("Preferences_backup.cpp", implode("\n",$lines));
$i=0;
while(strpos($lines[$i++],"DECLARE_PREF_GET")!==0);
while(trim($lines[$i++]));
array_splice($lines, $i-1, 0, $declare_pref);
$i+=sizeof($declare_pref);

while(strpos($lines[$i++],"\tSET_CONTROL_")===FALSE);
while(trim($lines[$i++]));
array_splice($lines, $i-1, 0, $init_value);
$i+=sizeof($init_value);

while(strpos($lines[$i++],"\tSET_CONTROL_")===FALSE);
while(trim($lines[$i++]));
array_splice($lines, $i-1, 0, $init_default);
$i+=sizeof($init_default);

while(strpos($lines[$i++],"\tGET_CONTROL_")===FALSE);
while(trim($lines[$i++]));
array_splice($lines, $i-1, 0, $onsave);
$i+=sizeof($onsave);

while(strpos($lines[$i++],"\tPREF_WRITE_")===FALSE);
while(trim($lines[$i++]));
array_splice($lines, $i-1, 0, $onsave_config);
$i+=sizeof($onsave_config);

while(strpos($lines[$i++],"\tPREF_INIT_")===FALSE);
while(trim($lines[$i++]));
array_splice($lines, $i-1, 0, $pref_init);
$i+=sizeof($onsave_config);


file_put_contents("Preferences.cpp", implode("\n",$lines));
