import React from 'react';
import logo from './logo.svg';
import './App.css';
import SimpleTable from './components/Table';

function App() {
    return (
        <TableContainer component={Paper}>
          <Table className={classes.table} aria-label="simple table">
            <TableBody>
              {grid.map((row) => (
                <TableRow>
                  <TableCell align="right" style={{borderRight: '1px solid black'}}>{row[0]}</TableCell>
                  <TableCell align="right" style={{borderRight: '1px solid black'}}>{row[1]}</TableCell>
                  <TableCell align="right" style={{borderRight: '1px solid black'}}>{row[2]}</TableCell>
                  <TableCell align="right" style={{borderRight: '1px solid black'}}>{row[3]}</TableCell>
                  <TableCell align="right" style={{borderRight: '1px solid black'}}>{row[4]}</TableCell>
                </TableRow>
              ))}
            </TableBody>
          </Table>
        </TableContainer>
    );
}

export default App;
