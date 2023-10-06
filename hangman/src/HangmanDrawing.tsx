const Head = (
    <div style={{
        width:"50px",
        height:"50px",
        borderRadius:"100%",
        border: "10px solid navy",
        position: "absolute",
        top: "50px",
        right:"-30px",
    }}/>
)


export default function HangmanDrawing(){return(
<div style={{
    position:"relative"
}}>
    {Head}

    <div style={{ height:"50px", width:"10px", background:"black", top:0, right:0, position:"absolute"}}/>
    {/* Soporte vertical */}
    <div style={{ height:"10px", width:"200px", background:"black", marginLeft:"120px"}}/> 
    {/* Palo de enmedio */}
    <div style={{ height:"400px",width:"10px",background:"black", marginLeft:"120px"}}/>
    {/* Base del ahorcado */}
    <div style={{ height:"10px",width:"250px",background:"black"}}/>
</div>
)}