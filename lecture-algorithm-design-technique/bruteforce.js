let totalResults = []
function combine(components, results) {
  if (results.length === components.length) {
    return totalResults.push(results.join(""))
  }
  for (let component of components) {
    let newResults = results.slice()
    if (newResults.indexOf(component) === -1) {
      newResults.push(component)
      combine(components, newResults)
    }
  }
}

// find the combinations
let components = ["+", "-", "*", "4", "5", "8", "3"]
combine(components, [])
console.log("There are " + totalResults.length + " possible combinations")

let validMathSolution = 0
let valid15Solution = 0
for (let solution of totalResults) {
  try {
    let value = eval(solution)
    if (value === 15) {
      valid15Solution ++
      console.error(solution)
    }
    validMathSolution ++
  } catch (error) {
    // just let it go...
  }
}
console.log("We have " + valid15Solution + " valid math solutions that result 15")
console.log("We have " + validMathSolution + " valid math solutions")
