<?php
function detectPhrase($article, $n) {
    $articles = explode(" ", $article);
    $phrases = [];
    for($i=0; $i<count($articles)-$n+1; $i++) {
        $acquiredPhrase = [];
        for($j=$i; $j<$i+$n; $j++) {
            $acquiredPhrase[] = $articles[$j];
        }
        $phrases[] = implode(" ", $acquiredPhrase); 
    }
    return $phrases;
}

$phrases = detectPhrase("pen pineapple apple pen pineapple", 2);
foreach($phrases as $phrase) {
    echo $phrase . "\n";
}
echo "\n";
$phrases = detectPhrase("pen pineapple apple pen pineapple", 3);
foreach($phrases as $phrase) {
    echo $phrase . "\n";
}?>