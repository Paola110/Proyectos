import HangmanDrawing from "./HangmanDrawing"
import HangmanWord from "./HangmanWord"
import Keyboard from "./Keyboard"

function App() {


  return (
    <div style={{
        MaxWidth: "800px",
        display: "flex",
        flexDirection: "column",
        gap: "2rem",
        margin: "0 auto",
        alignItems: "center"
    }}>
      <div style={{
        fontSize: "2rem",
        textAlign: "center"
      }}>
        Win or Lose
      </div>

      <HangmanDrawing/>
      <HangmanWord/>
      <Keyboard/>

    </div>

  )
}

export default App
