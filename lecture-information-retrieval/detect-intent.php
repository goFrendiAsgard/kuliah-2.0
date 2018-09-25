<?php
$dataSet = [
    ['forget it', 'cancel'],
    ['cancel', 'cancel'],
    ['ga jadi', 'cancel'],
    ['g jd', 'cancel'],
    ['jd g?', 'confirm'],
    ['jd?', 'confirm'],
    ['jadi?', 'confirm'],
    ['gimana?', 'confirm'],
];

function detectUniquePhrase($dataSet) {
    // ....
}

function detectUniqueWord($dataSet) {
    // "forget", "it", "cancel" ... "forget it"...
}

function articleToVector($article, $uniqueWords) {
    // [1, 2, 1, 1]
}

function getVectorLength($vector) {
    $length = 0;
    foreach($vector as $angka) {
        $length += $angka * $angka;
    }
    return pow($length, 0.5);
}

function dotMatrix($vector1, $vector2) {
    $result = [];
    for($i=0; $i<count($vector1); $i++) {
        $result[] = $vector1[$i] * $vector2[$i];
    }
    return $result;
}

function cosineSimilarity($vector1, $vector2) {
    $vector1Length = getVectorLength($vector1);
    $vector2Length = getVectorLength($vector2);
    return dotMatrix($vector1, $vector2) / ($vector1Length * $vector2Length);
}

function detectIntent($article, $dataSet) {
    $maxSimilarity = 0;
    $maxLabel = "";
    $articleVector = articleToVector($article);
    foreach($dataSet as $data) {
        $articleDataSet = $data[0];
        $labelDataSet = $data[1];
        $articleDataVector = articleToVector($articleDataSet);
        $similarity = cosineSimilarity($articleVector, $articleDataVector);
        if ($similarity > $maxSimilarity) {
            $maxSimilarity = $similarity;
            $maxLabel = $labelDataSet;
        }
    }
    return $maxLabel;
}

echo detectIntent('Gmn, g jd?', $dataSet); // "cancel", "confirm"
?>